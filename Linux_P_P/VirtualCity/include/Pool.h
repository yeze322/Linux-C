/*************************************************************************
	> File Name: Pool.h
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年03月28日 星期六 22时53分49秒
 ************************************************************************/
#ifndef _POOL_H
#define _POOL_H

#include "Socket.h"
#include "common.h"
#include "Thread.h"

using std::vector;
using std::queue;

class Pool
{
public:
	void run(Thread*,unsigned int);
	void fill_pool();
	void* add_pool(void*);
	Mutex lock_for_while_loop;
	Mutex lock_for_pool_capacity;
	unsigned int pool_capacity;
	vector<size_t> tid_set;
private:
	unsigned int MAX_POOL_NUM;
	Thread *ptr_PoolThread;
};

void Pool::run(Thread *thread, unsigned int MAX_NUM = 100)
{
	pool_capacity = 0;
	MAX_POOL_NUM = MAX_NUM;
	ptr_PoolThread = thread;
	fill_pool();
	add_pool(NULL);
}

void Pool::fill_pool()
{
	for(unsigned int i =0; i<MAX_POOL_NUM; i++){
		ptr_PoolThread->create();
		tid_set.push_back(ptr_PoolThread->gettid());
		pool_capacity+=1;
	}//fill the pool
	printf("pool finish[%u]\n",pool_capacity);
}

void* Pool::add_pool(void*)
{
	lock_for_while_loop.lock();
	while(1){
		if(pool_capacity<MAX_POOL_NUM){
			while(pool_capacity<MAX_POOL_NUM){
				ptr_PoolThread->create();
				tid_set.push_back(ptr_PoolThread->gettid());
				lock_for_pool_capacity.lock();
				pool_capacity+=1;
				lock_for_pool_capacity.unlock();
				//printf("add one thread !\n");
			}
		}
		lock_for_while_loop.lock();
	}	
}

#endif