#ifndef _MUTEXLOCK_H_
#define _MUTEXLOCK_H_

#include "common.h"

pthread_mutex_t DEFAULT_LOCK;

class MutexLock
{
public:
	MutexLock(pthread_mutex_t&);
	~MutexLock();
	void __unlock();
	pthread_mutex_t* __get_ptr_mutex();
private:
	/* data */
	pthread_mutex_t* ptr_mutex;
};

MutexLock::MutexLock(pthread_mutex_t& mutex = DEFAULT_LOCK)
{
	ptr_mutex = &mutex;
	pthread_mutex_lock(ptr_mutex);
}

MutexLock::~MutexLock()
{
	pthread_mutex_unlock(ptr_mutex);
}

void MutexLock::__unlock()
{
	pthread_mutex_unlock(ptr_mutex);
}

pthread_mutex_t* MutexLock::__get_ptr_mutex()
{
	return ptr_mutex;
}

#endif