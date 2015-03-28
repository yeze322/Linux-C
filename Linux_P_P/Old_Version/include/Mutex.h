#ifndef _MUTEX_H_
#define _MUTEX_H_
#include "common.h"
class Mutex{
public:
    Mutex();
    ~Mutex();
    
    void lock() {int ret = pthread_mutex_lock(mutex); if(ret) perror("Mutex::lock()");}
    int trylock() {int ret = pthread_mutex_trylock(mutex); if(ret) perror("Mutex::trylcok()");};
    int unlock() {int ret = pthread_mutex_unlock(mutex); if(ret) perror("Mutex::unlock()");} ;
private:
    pthread_mutex_t *mutex;
    pthread_mutex_t* get_pMutex(); //seems no use
};

Mutex::Mutex(){
    mutex =  new pthread_mutex_t;
    int ret = pthread_mutex_init(mutex,NULL);
    if(ret)
        perror("init mutex failed!");
}

Mutex::~Mutex(){
    int ret = pthread_mutex_destroy(mutex);
    if(ret) perror("Mutex::~Mutex");
    delete mutex;
}

pthread_mutex_t* Mutex::get_pMutex()
{ //seems no use
    return mutex;
}
#endif