/*************************************************************************
> File Name: client.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月09日 星期一 15时10分41秒
************************************************************************/

#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<signal.h>
#define IP "192.168.1.53"
#define port 1234


int send_buf(int sfd,char *buf,int len)
{
    int send_sum = 0;
    int send_return;
    while(send_sum<len)
    {
        send_return = send(sfd,buf+send_sum,len - send_sum,0);
        send_sum += send_return;

    }
    return send_sum;

}

int recv_buf(int sfd,char *buf,int len)
{
    int send_sum = 0;
    int send_return;
    while(send_sum<len)
    {
        send_return = recv(sfd,buf+send_sum,len - send_sum,0);
        send_sum += send_return;

    }
    return send_sum;

}
void init(struct sockaddr_in* my)
{
    memset(my,0,sizeof(struct sockaddr_in));
    my->sin_family = AF_INET;
    my->sin_port = htons(port);
    my->sin_addr.s_addr = inet_addr(IP);

}
int main(int argc,char *argv[])
{
    int fd_client;
    fd_client = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in seraddr;
    init(&seraddr);
    connect(fd_client,(struct sockaddr*)&seraddr,16);
    char msg[1024];
    memset(msg,0,1024);
}
//120.24.236.135
