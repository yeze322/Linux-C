/*************************************************************************
> File Name: client.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月08日 星期日 11时14分02秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SER_IP "192.168.1.32"
#define SER_PORT 1234
int send_buf(int sfd,char *buf,int len);//if sendn <  I send num, then continue
void per(int a);
int main(int argc,char *argv[])
{
    int fd_client = socket(AF_INET,SOCK_STREAM,0);
    //connect
    struct sockaddr_in seraddr;
    memset(&seraddr,0,sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(SER_PORT);
    seraddr.sin_addr.s_addr = inet_addr(SER_IP);
    int judge = connect (fd_client,\
        (struct sockaddr*)&seraddr,sizeof(seraddr));
    printf("connet\n");
    per(judge);
    //send 
//    char p[1024] = "";
    
    int *parr = (int *)calloc(1024*100,sizeof(int));
    //int recvn = recv(fd_client,parr,1024*40,0);
    int sendn = send(fd_client,parr,1024*400,0);
    printf("sendn = %d\n",sendn);
//    数据量下的发送会丢失、接收会丢失。因此高速传输是要考虑的问题   加入缓冲区？
/*
    while(1){
        memset(p,0,1024);
        read(0,p,1024);
        send(fd_client,p,strlen(p),0);
        recv(fd_client,p,1024,0);
        printf("from server: %s\n",p);
    }
    */
    close(fd_client);
    return 0;
}

int send_buf(int sfd,char *buf, int len)
{//char * because sizeof(char) == 1,
    int send_sum = 0;
    while(send_sum<len)
    {
        send_sum += send(sfd,buf+send_sum,len-send_sum,0);
    }
}

void per(int a)
{
    if(a == -1)
    {
        perror("-1\n");
        exit(1);

    }
}

