/*************************************************************************
	> File Name: productor_and_consimer.c
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年02月06日 星期五 21时00分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t lock;
void* consume(void *arg);
void* product(void *arg);

int main(int argc,char *argv[])
{
    char buf_pool[1024]="";
    int i_thread_num = atoi(argv[1]);
    int i_ticket_num = atoi(argv[2]);

    pthread_t productor;
    pthread_t *consumer = (pthread_t *)calloc(i_thread_num,sizeof(pthread_t));
    printf("%d\n",sizeof(pthread_t));
}
