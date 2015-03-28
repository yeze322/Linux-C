#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include "common.h"
#include "Thread.h"
using std::queue;

class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();
	void init(Thread&);
private:
	/* data */
	queue<Thread>* pool; 

};

ThreadPool::ThreadPool()
{
	pool = NULL;
}

ThreadPool::~ThreadPool()
{
	delete pool;
}

void ThreadPool::init(Thread& )
{
	pool = new queue<Thread>(10,Thread);
}


#endif 
//_THREADPOOL_H_