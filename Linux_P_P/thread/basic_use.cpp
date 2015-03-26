#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
typedef void* (*p_FUNC)(void *);
typedef void* FUNCTION(void*);
FUNCTION printid;
void p(const char *);
/* ============================ */
class Thread
{
public:
    Thread(p_FUNC func,void *arg) ;
    ~Thread();
    pthread_t create();
    void join(void*,size_t);
    size_t gettid(){return tid;}
    void cancel(size_t);
    void detach();
private:
    /* data */
    p_FUNC func;
    pthread_t tid;
    void* arg;
};

Thread::Thread(p_FUNC func, void *arg = NULL)
{
    p("Thread initailizing!");
    this->arg = arg;
    this->func = func;
}

Thread::~Thread()
{
    cancel(gettid());
}

pthread_t Thread::create()
{
    p("creating thread!!");
    int err = pthread_create(&tid,NULL,func,arg);
    if (err){
        perror("create thread failed!\n");
    }
    return tid;
}

void Thread::join(void* retval = NULL,size_t datasize = 0)
{
    assert(retval!=NULL||datasize==0);
    void* ret;
    int error = pthread_join(tid,&ret);
    p("join thread!\n");
    if (error){
        printf("join thread failed! tip = %lu\n",pthread_self());
    }
    if(datasize)
        strncpy((char*)retval,(char*)&ret,datasize);
    return;
}

void Thread::cancel(size_t tid_cancel){
    int err = pthread_cancel(tid_cancel);
    if(err){
        p("in Thread::cancel, cancel failed!\n");
    }
}

/* =================================== */
int main(int argc,char *argv[])
{
    Thread td(printid);
    pthread_t p1 = td.create();
    sleep(1);
    int retval;
    td.join(&retval,sizeof(retval));
    printf("retval = %s\n",(char*)&retval);
    return 0;
}

void p(const char *str){
    printf("%s\n",str);
}

void* printid(void *){
    pthread_t tid = pthread_self();
    printf("tid = %lu\n",tid);
    p("printif function start!");
    pthread_exit((void*)0x00616161);
}

