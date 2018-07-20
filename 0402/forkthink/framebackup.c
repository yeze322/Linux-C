/*************************************************************************
> File Name: whyfork.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月04日 星期三 22时06分11秒
************************************************************************/
#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
void commoninit();
void detectlogin();
void userlogin();
void connectpipe();
void keeplistening();
void keepwrite();
int main(int argc,char *argv[])
{
    int brunch=fork();
    commoninit();

    if(brunch==0)//means it's child
    {
        //sharepid
        key_t username = ftok
        printf("this is : %d \n",getpid());
        while(1){
            sleep(5);
            printf("detectlogin\n");
            detectlogin();
            int login=fork();
            if(login == 0){
                connectpipe();
                //share++,divide share into two halves, one record listen,one write
                printf("connectpipe, %d,father %d\n",getpid(),getppid());
                keeplistening();
            }
            else{
                printf("this is login[%d], still listenning to login\n",getpid());
            }
        }
    }else{
        keepwrite();
        printf("I'm trunk[%d],my father is [%d],I'm doing some importan thing\n",getpid(),getppid());
        wait(NULL);
    }
}

void commoninit(){}
void detectlogin(){}
void userlogin(){}
void connectpipe(){}
void keeplistening(){while(1)  ;}
void keepwrite(){while(1)  ;}
