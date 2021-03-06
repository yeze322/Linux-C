/*************************************************************************
> File Name: server_socket.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月08日 星期日 10时29分54秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SERVER_IP "192.168.1.32"
#define SERVER_PORT 1234
void per(int a)
{
    if(a == -1)
    {
        perror("-1\n");
        exit(1);
    }
}
int main(int argc,char *argv[])
{
    //1-soclet
    int fd_listen = socket (AF_INET,SOCK_STREAM,0);
    printf("listen\n");
    per(fd_listen);

    //2-bind
    struct sockaddr_in seraddr;
    memset(&seraddr,0,sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(SERVER_PORT);
    seraddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    int judge = bind(fd_listen,(const struct sockaddr*)&seraddr,sizeof(seraddr));
    printf("bind\n");
    per(judge);
    //3-listen
    judge = listen(fd_listen,5);
    per(judge);
    printf("listen finish\n");
    //4-int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen); it's a block fun
    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);
    memset(&clientaddr,0,sizeof(clientaddr));
    int fd_client;
    while(1)
    {
        fd_client = accept(fd_listen,\
            (struct sockaddr*)&clientaddr,&len);
        printf("fdclient = %d \n",fd_client);
        per(fd_client);
        printf("%s: %d connect!\n",\
               inet_ntoa(clientaddr.sin_addr),\
               ntohs(clientaddr.sin_port));
        if(fork()==0)
        {
            char buf[1024] = "";
            while(memset(buf,0,1024),recv(fd_client,buf,1024,0)!=0)
            {
                printf("recv from client: %s\n",buf);
                send(fd_client,buf,strlen(buf),0);//write
            }    
            exit(0);
        }
    }
    //5- print the server info
    //6-recv
    
    close(fd_listen);
    close(fd_client);
}
