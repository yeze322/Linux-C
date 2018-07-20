/*-****************************************************************
> Name: users.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月04日 星期三 16时55分27秒
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
#define LOGIN "login.fifo"
#define PATH "./pipe/"
void sendtoserver();//from stdin
void recvandprint();
void nametopipename(char *name,char *name1,char *name2);

int main(int argc, char *argv[])//send in user's name
{
    int login=open(LOGIN,O_WRONLY);
    char name[128]="";
    sprintf(name,"%s",argv[1]);
    write(login,name,strlen(name));
    //send login signal to server
    char name1[128],name2[128];
    nametopipename(argv[1],name1,name2);
    mkfifo(name1,0666);
    mkfifo(name2,0666);
    printf("cannot open pipe,%s--%s\n",name1,name2);
    int send=open(name1,O_WRONLY);//name.send.fifo
    int recv=open(name2,O_RDONLY);//name.recv.fifo
    //create two fifo used for reading and writing
    char buf[1024];
    char message[1024];
    //share used to record users,share[0] can record number
    //try to write a benchmark program
    int pid=fork();
    printf("split success!\n");
    if(pid==0)//child process,used to send to server
    {
        while(1)
        {
            printf("child to write\n");
            memset(buf,0,1024);
            memset(message,0,1024);
            read(0,buf,1024);
            printf("input activate buf = %s\n",buf);
            if(strcmp(buf,"")==0)//means ctrl+D
            {
                write(send,"EOF\0",4);
                exit(1);
            }
            sprintf(message,"%s: %s",argv[1],buf);
            write(send,message,strlen(message));
        }

    }else if(pid > 0)
    {
        while(1)
        {
            read(recv,buf,1024);
            if(strcmp(buf,"EOF")==0)
            exit(0);
            printf("%s\n",buf);
        }
    }
}
void nametopipename(char *name,char *name1,char *name2)
{
    memset(name1,0,128);
    sprintf(name1,"%s.send.fifo",name);  
    memset(name2,0,128);
    sprintf(name2,"%s.recv.fifo",name);
}

