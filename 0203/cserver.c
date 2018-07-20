/*************************************************************************
> File Name: server.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年03月02日 星期一 11时32分01秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
/* after finish, change this line to get IP auto */
#define SER_PORT 1234

char *SER_IP;
void per(int a){if(a == -1){perror("failed,-1\n");exit(1);}}
void init_sockaddr_in(struct sockaddr_in *seraddr);
void send_main(int fd_client,char *);
void son(int fd_client);
void send_main(int fd_client,char *yourfile);
void save(int fd_client);

void sock_main(int port)
{
    /* 1 - socket */
    int fd_listen = socket(AF_INET,SOCK_STREAM,0);
    printf("listen\n");
    per(fd_listen);

    /* 2 - bind */
    struct sockaddr_in seraddr;
    init_sockaddr_in(&seraddr);

    printf("bind\n");
    int judge = bind(fd_listen,(const struct sockaddr*)&seraddr,sizeof(seraddr));
    per(judge);

    /* 3 - listen */
    judge = listen(fd_listen,5);
    per(judge);
    printf("listen finishi\n");

    /* 4 - accept */
    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);
    memset(&clientaddr,0,sizeof(clientaddr));

    int fd_client;
    while(1){
        fd_client = accept(fd_listen,\
                           (struct sockaddr*)&clientaddr,&len);
        printf("fd_client = %d\n",fd_client);
        per(fd_client);
        printf("%s:%d connect!\n",\
               inet_ntoa(clientaddr.sin_addr),\
               ntohs(clientaddr.sin_port));
        if(fork()==0)
        {
            son(fd_client);
            break;
        }
        close(fd_client);
    }

    close(fd_listen);
}

int main(int argc,char *argv[])
{
    char ip[20];
    scanf("%s",ip);
    SER_IP=ip;
    printf("ip : %s\n",ip);
    sock_main(SER_PORT); 
    printf("this fork return!\n");
}

void save(int fd_client)
{
    char fileName[30]="";
    while(recv(fd_client,fileName,30,0)==0)
    memset(fileName,0,30);
    send(fd_client,fileName,1,0);
    printf("filenamw arrived: %s\n",fileName);
    /* shake hand X3 */
    char path[30]="";
    sprintf(path,"./%s",fileName);
    int fd = open(fileName,O_WRONLY|O_CREAT,0777);
    FILE *fp_recv = fdopen(fd,"w");
    /* ADD: mask and permission must be made sure before! */
    if(fwrite==NULL)
    printf("create failed\n");
    else printf("start recv!\n");
    char p[1024];
    while(1){
        memset(p,0,1024);
        int recvnum = recv(fd_client,p,1024,0);
        fwrite(p,1,recvnum,fp_recv);
        if(recvnum<1024)
            break;
    }
    fclose(fp_recv);
    close(fd);
    printf("recv finishi\n");
    send(fd_client,fileName,1,0);
}
void send_main(int fd_client,char *yourfile)
{
    printf("you want to send: %s\n",yourfile);
    //send 
    /* now finish analyse. */
    char p[1024] = "";
    FILE *fp_send = fopen(yourfile,"r");
    if(fp_send == NULL){
        perror("open file failed\n!");
        return;
    }
    printf("open success!\n");
    /* ADD: TRANS path to file */
    send(fd_client,yourfile,30,0);
    while(recv(fd_client,yourfile,1,0)==0)
        ;
    printf("shake hand finish!!!\n");
    /* shake hand X3 */
    while(1){
        memset(p,0,1024);
        int sendnum = fread(p,1,1024,fp_send);
        if(sendnum < 1024){
            send(fd_client,p,sendnum,0);
            memset(p,0,1024);
            break;
        }
        send(fd_client,p,1024,0);
    }
    while(recv(fd_client,p,1,0)==0)
        ;
    printf("upload scuccess!\n");
    fclose(fp_send);
}

void son(int fd_client)
{
    while(1){
        char dowhat[100];
        memset(dowhat,0,100);
        /* ADD: shake hand X3 */
        while(recv(fd_client,dowhat,100,0)==0)
            memset(dowhat,0,100); 
        send(fd_client,dowhat,1,0);
        printf("command arrived: %s\n",dowhat);
        if(strcmp(dowhat,"EOF")==0){
            printf("client: %d offline\n",fd_client);
            return;
        }
            
        if(strcmp(dowhat,"upload")==0||strcmp(dowhat,"u")==0){
            printf("\n\n====save====\n\n");
            save(fd_client);
            printf("\n\n====save finish====\n\n");
            continue;
        }
             
        if(strcmp(dowhat,"d")==0||strcmp(dowhat,"download")==0){
            printf("\n\n====download file====\n\n");
            char filename[30]="";
            while(recv(fd_client,filename,25,0)==0)
                memset(filename,0,30);
            printf("recv filename!%s\n",filename);
            send_main(fd_client,filename);
            printf("\n\n====file finish====\n\n");
            continue;
        }
   }
}

void print(int fd_client)
{
    /* fork a son tow read and writeL */
    char buf[1024] = "";
    while(memset(buf,0,1024),recv(fd_client,buf,1024,0)!=0)
    {
        printf("%s",buf);
        send(fd_client,buf,strlen(buf),0);
    }
}

void init_sockaddr_in(struct sockaddr_in *seraddr)
{    
    memset(seraddr,0,sizeof(seraddr));
    seraddr->sin_family = AF_INET;
    seraddr->sin_port = htons(SER_PORT);
    seraddr->sin_addr.s_addr = inet_addr(SER_IP);
}

