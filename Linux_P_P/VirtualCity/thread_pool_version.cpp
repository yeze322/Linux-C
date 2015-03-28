/* ========== */
#include "CITY.h"
#include "Socket.h"
#include "common.h"
#include "Thread.h"
#include "Pool.h"

using std::vector;

thread_FUNC Usr_Function;
thread_FUNC KILL_ALL_THREAD;

Socket_Connect sock;
int main()
{
	sock.PowerOn();
	Pool thread_pool;

	Thread manager(KILL_ALL_THREAD,(void*)&thread_pool.tid_set);
	manager.create();

	Thread city(Usr_Function,(void*)&thread_pool);
	thread_pool.run(&city);//this function won't return 
	return 0;
}

void* KILL_ALL_THREAD(void* arg)
{
	vector<size_t>* ptr_tid_set = (vector<size_t>*)arg;
	char buf[100] = "";
	read(0,buf,100);
	for(vector<size_t>::iterator i = ptr_tid_set->begin(); i != ptr_tid_set->end(); i++){
		pthread_cancel(*i);
	}
	close(sock.getSocketID());
	exit(0);
}

/*
this Usr_Function is based on CITY class. 
Normally, you should make sure this function works like a consumer.
That means : it consume one thread.
It can also be activated by Socket IO.(which is the mainly use)
*/
void* Usr_Function(void* arg)
{
	Pool *pool = (Pool *)arg;
	//add accept here
	int fd_client = sock.Accept();
	//poor at concurrency
	pool->lock_for_pool_capacity.lock();
	pool->pool_capacity -= 1;//put this back, or when MAX_NUM == 1, the Usr_Function run so fast...
	pool->lock_for_pool_capacity.unlock();
	pool->lock_for_while_loop.unlock();

	CITY lord(fd_client);
	lord.run();
	return NULL;
}