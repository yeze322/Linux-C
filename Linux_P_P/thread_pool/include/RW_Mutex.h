#include "common.h"

#define O_UNLOCK 0
#define RD_ONLY 1
#define WR_ONLY 2
#define O_LOCK 3

class RW_Mutex
{
public:
    RW_Mutex();
    ~RW_Mutex();
    
    void unlock() {int ret = pthread_rwlock_unlock(mutex); if(ret) perror("RW_Mutex::unlock");};
    void rdlock() {int ret = pthread_rwlock_rdlock(mutex); if(ret) perror("RW_Mutex::rdlock");};
    void try_rdlock() {int ret = pthread_rwlock_tryrdlock(mutex); if(ret) perror("RW_Mutex::try_rdlock");};
    void wrlock() {int ret = pthread_rwlock_wrlock(mutex); if(ret) perror("RW_Mutex::wrlock");};
    void try_wrlock() {int ret = pthread_rwlock_trywrlock(mutex); if(ret) perror("RW_Mutex::try_wrlock");};
    void lock(int);

private:
    /* data */
    pthread_rwlock_t *mutex;
    /* functiions */
    pthread_rwlock_t* get_ptr_rwMutex();
};

RW_Mutex::RW_Mutex()
{
    mutex = new pthread_rwlock_t;
    int ret = pthread_rwlock_init(mutex,NULL);
    if(ret){
        perror("init rwlock failed!");
    }
}

RW_Mutex::~RW_Mutex()
{
    int ret = pthread_rwlock_destroy(mutex);
    if (ret){
        perror("destroy rwlock faiiled!");
    }
    delete(mutex);
}

pthread_rwlock_t* RW_Mutex::get_ptr_rwMutex(){
    return mutex;
}

void RW_Mutex::lock(int status = 3)
{
    assert(status <=3 && status >=0);
    switch(status){
        case 0: unlock(); break;
        case 1: wrlock(); break;
        case 2: rdlock(); break;
        case 3: wrlock(); rdlock(); break;
    }
}