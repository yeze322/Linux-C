/*************************************************************************
> File Name: add_n_thread.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月06日 星期五 15时05分50秒
************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int number=0;
void* add(void *ii)
{
    int *num=(int*)ii;
    int count=10000;
    while(--count)
    {
        (*num)++;
    }
    return NULL;
}

void* addlk(void *arg)
{
    pthread_mutex_t *plock = (pthread_mutex_t*)arg;
    int cnt=10000;
    while(--cnt)
    {
        pthread_mutex_lock(plock);
        number++;
        pthread_mutex_unlock(plock);
    }
    pthread_exit(NULL);
}

int main(int argc,char *argv[])
{
    pthread_t p1,p2;
    int i=0;
    int *ii=&i;
    pthread_mutex_t lock;
    pthread_mutex_init(&lock,NULL);
    printf("argc = %d   ",argc);
    if(argc-1>0)
    {
        pthread_create(&p1,NULL,addlk,(void*)&lock);
        pthread_create(&p2,NULL,addlk,(void*)&lock);//if U want to add both i and lock, need to create a structure,try to do it yourself
        pthread_join(p1,NULL);
        pthread_join(p1,NULL);
        pthread_mutex_destroy(&lock);
        printf("i = %d",number);
    }
    else{
        pthread_create(&p1,NULL,add,(void*)ii);
        pthread_create(&p2,NULL,add,(void*)ii);
        pthread_join(p1,NULL);
        pthread_join(p1,NULL);
        printf("i = %d",i);
    }
    putchar('\n');
}
