#include "Thread.h"
#include "common.h"
#include "Mutex.h"
#include "Barrier.h"
#include "MutexLock.h"
/* =================================== */
thread_FUNC printid;
//pthread_barrier_t wall;
pthread_mutex_t num_lock;
struct NUM{
	int num;
	//Mutex num_lock;
};

void* addnum(void * arg){
	p("add num start!");
	NUM* a = (NUM *)arg;
	for(int i = 0;i<9999999;i++){
		MutexLock temp(num_lock);
		//a->num_lock.lock();
		a->num  = a->num + 1;
		//a->num_lock.unlock();
	}
	printf("a = %d\n",a->num);
	printf("tid = %lu, finish!\n",pthread_self());
	//sleep(1);
}

int main()
{
	NUM a;
	a.num = 0;
	Thread t1(addnum,&a);
	Thread t2(addnum,&a);
	t1.create();
	t2.create();
	t1.join();
	t2.join();
	printf("num a  =  %d\n",a.num);
	return 0;
}


/*
void* printid(void *){
    pthread_t tid = pthread_self();
    printf("tid = %lu\n",tid);
    p("printif function start!");
    pthread_exit((void*)0x00616161);
}

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

Barrier wall(2);

	wall.wait();

	wall.wait();

	p("wait wall");

	//wall.wait();
*/