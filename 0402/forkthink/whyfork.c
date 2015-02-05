/*************************************************************************
> File Name: whyfork.c
> Author: Yeze
> Mail: 2295905420@qq.com
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
#define PUBLIC "public.fifo"
#define LOGFILE "login.fifo"
#define USRLEN 20
int connectpipe(char *);
void keeplistening(int);
void keepwrite();
int main(int argc,char *argv[])
{
    //sharepid
    //save what? user's name! 
    //way 1: put it in a char[20], share a 20*512 space;
    //way 2: put it in longlong, then transfer it to char(use ascii)
    //e.g. abcd --> 'a' + [0,1,2,3,4] --> 05 'a' 01 02 03 04. only save half memory
    //improve: use '0' -- asc 48 as basic char, only need (num c0 c1 c2...)
    //I can use address!
    //but think about it: why share memory is invented? 'cause we needn't save it twice
    int userspace = shmget(IPC_PRIVATE,USRLEN*513,0666);
    char *temp = (char *)shmat(userspace,NULL,0);
    memset(temp,0,USRLEN*513);
    //commoninit
    mkfifo(LOGFILE,0666);
    int login=open(LOGFILE,O_RDONLY);
    char buf[1024];

    int brunch=fork();
    if(brunch==0)//listen login, and save the user name in shm
    {
        //one brunch loop here
        char lgname[USRLEN];
        printf("start listening\n");
        while(memset(lgname,0,USRLEN),read(login,lgname,USRLEN-1)!=0){
            int iflogin=strcmp(lgname,"");  
            if(iflogin)
            {
            /*    //visit the share and add an element
                int *count = (int *)shmat(userspace,NULL,0);
                (*count)++;
                //if I share an address, when I fork, two copy will be Created
                //is it right to change the value by use the pointer?
                char *thisuser=(char *)shmat(userspace,NULL,0)+*count*USRLEN;
                strncpy(thisuser,lgname,USRLEN);*/
                
                //beter to open it in child, and write share memory.so problem:
                //if write too fast, we must add some lock to wait all finish reading
            }
        }
    }else{
        //one for write to the users in shm, one for read from PUBLIC
        keepwrite();
        wait(NULL);
    }
}

int connectpipe(char *thisuser){
    int write = open(thisuser,O_WRONLY);
/*
    int write = connectpipe(thisuser);
    keeplistening(write);               */
}
void keeplistening(int write){
    printf("now start listening\n");
    while(1);
}
void keepwrite(){
    printf("now keep transfer messages\n");
    while(1);
}
