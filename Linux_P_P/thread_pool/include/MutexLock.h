#include "common.h"

pthread_mutex_t DEFAULT_LOCK;

class MutexLock
{
public:
	MutexLock(pthread_mutex_t&);
	~MutexLock();
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