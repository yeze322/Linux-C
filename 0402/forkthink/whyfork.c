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
    int userspace = shmget(IPC_PRIVATE,USRLEN*3,0666);
    char *temp = (char *)shmat(userspace,NULL,0);
    memset(temp,0,USRLEN*3);
    //commoninit
    mkfifo(LOGFILE,0666);
    mkfifo(PUBLIC,0666);
    int login=open(LOGFILE,O_RDONLY);
    char buf[1024];

    int brunch=fork();
    if(brunch==0)//listen login, and save the user name in shm
    {
        //one brunch loop here
        char lgname[USRLEN];
        printf("1.1 start listening\n");
        while(memset(lgname,0,USRLEN),read(login,lgname,USRLEN-1)!=0){
            int iflogin=strcmp(lgname,"");  
            if(iflogin)
            {
                //visit the share and add an element
                int *count = (int *)shmat(userspace,NULL,0);
                (*count)++;
                //if I share an address, when I fork, two copy will be Created
                //is it right to change the value by use the pointer?
                char *thisuser=(char *)(shmat(userspace,NULL,0)+*count*USRLEN);
                strncpy(thisuser,lgname,USRLEN);
                printf("1.2 some body login! %s\n",thisuser);

                //beter to open it in child, and write share memory.so problem:
                //if write too fast, we must add some lock to wait all finish reading
            }
        }
    }else{
        //one for write to the users in shm, one for read from PUBLIC
        //keepwrite();
        printf("2.1 for transfer success\n");
        int pubpipe = open(PUBLIC,O_RDONLY);
        printf("2.2 pipe open suc\n");
        int i;
        int fp[512]={0};
        while(1){
            int *count = (int *)shmat(userspace,NULL,0);
            for(i=1;i<=*count;i++)
            {
                char *p = (char *)(shmat(userspace,NULL,0)+i*USRLEN);
                printf("now user: %s %p\n",p,p);
                fp[i]=open(p,O_WRONLY);
            }
            memset(buf,0,1024);
            read(pubpipe,buf,1024);
            printf("%s",buf);
            if(strcmp(buf,"")==0)
            continue;
            if(strstr(buf,":")==NULL)//logoff operation
            {
                for(i = 1;i<=*count;i++)
                {
                    char *p = (char *)shmat(userspace,NULL,0)+i*USRLEN;
                    printf("now user: %s %p\n",p,p);
                    if(strcmp(buf,p)==0){
                        write(fp[i],"EOF\0",4);
                        memset(p,0,USRLEN);
                        (*count)--;
                        printf("%s is offline\n",buf);
                        //now move element ,make sure no empty
                        int j;
                        break;
                    }
                }
                for(i;i<=*count;i++)
                {                  
                    char *p = (char *)shmat(userspace,NULL,0)+i*USRLEN;
                    if(strcmp(p,"")==0){
                        strcpy(p,p+USRLEN);
                        memset(p+USRLEN,0,USRLEN);
                    }
                }
                continue;
            }
            printf("count = %d\n",*count);
            for(i=1;i<=*count;i++)
            {
                char *p = (char *)shmat(userspace,NULL,0)+i*USRLEN;
                write(fp[i],buf,1024);
                close(fp[i]);
            }
        }
    }
}
