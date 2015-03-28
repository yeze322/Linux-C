#ifndef _THREAD_H_
#define _THREAD_H_
#include "common.h"
/* ============================ */

void p(const char *str){
    printf("%s\n",str);
}
typedef void* (*p_thread_FUNC)(void *);
typedef void* thread_FUNC(void*);

class Thread
{
public:
    Thread(p_thread_FUNC func,void *arg) ;
    //~Thread();
    pthread_t create();
    void join(void*,size_t);
    size_t gettid(){return tid;}
    void kill(pthread_t);
    void cancel();
    //void detach();
private:
    /* data */
    p_thread_FUNC func;
    pthread_t tid;
    void* arg;
};

Thread::Thread(p_thread_FUNC func, void *arg = NULL)
{
    p("Thread initailizing!");
    this->arg = arg;
    this->func = func;
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
void Thread::cancel(){
    int err = pthread_cancel(tid);
    if(err) perror("Thread::cancel");
    else p("cancel self success!");
}

void Thread::kill(pthread_t tid_cancel){
    int err = pthread_cancel(tid_cancel);
    if(err) p("in Thread::cancel, cancel failed!");
    else printf("kill thread %lu success!",tid_cancel);
}
#endif