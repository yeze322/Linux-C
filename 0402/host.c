/*****************************************************************
  > Name: host.c
  > Author: Yeze
  > Mail: a@b.com
  > Created Time: 2015年02月04日 星期三 16时44分06秒
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
#define PATH "./"
#define WRTOALL "svdata.fifo"

void childsend();
void childrecv();
void nametopipename(char *name,char *name1,char *name2);

int main(int argc,char *argv[])
{
    int user[1024]={0};
    mkfifo(LOGIN,0666);
    char lgname[128]="";
    sprintf(lgname,"%s%s",PATH,LOGIN);
    mkfifo(lgname,0666);
    int login=open(lgname,O_RDONLY);
    char buf[1024];
    // FILE *fp=fopen(login,"r"
    int shmid=shmget(IPC_PRIVATE,2052,0666);//0666 means perimission,because max open is 1024,so share 512 is enough
    int *share=(int *)shmat(shmid,NULL,0);
    share[0]=0;

    while(1)
    {
        memset(lgname,0,128);
        read(login,lgname,128);
        if(strcmp(lgname,"")!=0)
        {
            printf("somebody login, name: %s\n",lgname);
            share[0]++;
            char willread[128],willwrite[128];
            nametopipename(lgname,willread,willwrite);
            printf("name1--%s\n name2--%s\n",willwrite,willread);
            if(fork()==0)//child keep print message
            {
                int fdread=open(willread,O_RDONLY);
                printf("child pipe print , name:%s",lgname);
                int *users=shmget
                while(1)
                {
                    memset(buf,0,1024);
                    read(fdread,buf,1024);
                    printf("%s",buf);
                    //set share memory space
                }
            }else{
                int fdwrite=open(willwrite,O_WRONLY); 
                printf("parent pipe transmessage, %s",lgname);
                while(1)
                {
                    memset(buf,0,1024);
                    read(fdwrite,buf,1024);
                    printf("%s",buf);
                }
            }
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

