/* ========== */
#include "CITY.h"
#include "Socket.h"
#include "common.h"
#include "Thread.h"

using std::vector;
using std::queue;
using std::cout;
using std::endl;

Socket_Connect sock;

thread_FUNC user;
thread_FUNC sendmsg;

Mutex lock_for_pool_capacity;

int main()
{
	sock.PowerOn();

	int pool_capacity = 0;

	Thread city(user,(void*)&pool_capacity);
	vector<size_t> tid_set;
	int MAX_POOL_NUM = 1000;

	for(int i =0; i<MAX_POOL_NUM; i++){
		city.create();
		tid_set.push_back(city.gettid());
		pool_capacity+=1;
	}//fill the pool

	Thread manager(sendmsg,(void*)&tid_set);
	manager.create();

	while(1){
		lock_for_pool_capacity.lock();
		if(pool_capacity<MAX_POOL_NUM){
			while(pool_capacity<MAX_POOL_NUM){
				city.create();
				tid_set.push_back(city.gettid());
				pool_capacity+=1;
				printf("add one thread!\n");
			}
		}
	}
	return 0;
}

void* sendmsg(void* arg)
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

void* user(void* arg)
{
	int *pool_capacity = (int *)arg;
	//add accept here
	int fd_client = sock.Accept();

	lock_for_pool_capacity.unlock();
	*pool_capacity -= 1;

	CITY lord(fd_client);
	lord.run();
	return NULL;
}