/*************************************************************************
> File Name: a_test_for_shm_about_pointer.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月05日 星期四 15时11分53秒
************************************************************************/
//经过验证，果然是不行的！
//同一个内存地址在不同的进程之间并非相同的意义
//具体的请理解内存远离
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc,char *argv[])
{
    int shm_pointer =  shmget(IPC_PRIVATE,8,0666);
    int pid = fork();
    if(pid>0)
    {
        long int *pointer = (long int *)shmat(shm_pointer,NULL,0);
        char str[10]="hello";
        *pointer =(long int )str;
        printf("%0x,sizechar *:%d,  sizeof int %d\n",\
               *pointer,sizeof(char *),sizeof(long int));
        printf("-%c-\n",*((char *)(*pointer)));
    }else if(pid == 0){
        sleep(1);
        long int *q=(long int*)shmat(shm_pointer,NULL,0);
        printf("q= %s\n",((char *)(*q)));
//        printf("str = %s\n",*q);
    }
    getchar();
 }

