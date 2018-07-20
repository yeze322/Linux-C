/*************************************************************************
	> File Name: server.c
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年02月09日 星期一 11时26分47秒
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
#include<sys/wait.h>
#define IP "192.168.1.53"
#define port 1234
void iferr(int a)
{
    if(a==-1)
    perror("-1");
    exit(1);
}
void child_main();
void child_handle(int sign)
{
    wait(NULL);
}
void init(struct sockaddr_in* my)
{
    memset(my,0,sizeof(struct sockaddr_in));
    my->sin_family = AF_INET;
    my->sin_port = htons(port);
    my->sin_addr.s_addr = inet_addr(IP);
}

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
int main(int argc, char *argv[])
{
    int fd_listen;
    fd_listen = socket(AF_INET,SOCK_STREAM,0);
    signal(17,child_handle);
    iferr(fd_listen);
    struct sockaddr_in my,clientaddr;
    socklen_t sock_len = sizeof(clientaddr);
    init(&my);
    iferr(bind(fd_listen,(struct sockaddr*)&my,16));
    iferr(listen(fd_listen,5));
    int client;
    printf("start\n");
    while(1){
        sock_len = sizeof(clientaddr);
        memset(&clientaddr,0,(int)sock_len);
        client = accept(fd_listen,(struct sockaddr*)&clientaddr,&sock_len); 
        printf("client : %s:%d connrct!\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port)) ;
        if(fork()==0)
        {
            close(fd_listen);
            child_main(client);
            close(client);
            exit(1);
        }
        close(client);
    }
    printf("end\n");
    wait(NULL);
}

void child_main(int fd_client)
{
    int recv_len;
    recv_buf(fd_client,(char*)&recv_len,4);//length
    char filename[128]="";
    recv_buf(fd_client,filename,recv_len);
    printf("file :%s\n",filename);
    int fpsend = open(filename,O_RDONLY);
    if(fpsend == -1)
    {
        char nofile[128]="no file\n";
        int lenit = strlen(nofile);
        send(fd_client,(char*)&lenit,4,0);
        send_buf(fd_client,nofile,lenit);
        return;
    }
    char msg[1024];
    int sendlen;
    while(memset(msg,0,1023),sendlen = read(fpsend,msg,1024)!=0)
    {
        send(fd_client,(char *)&sendlen,4,0);
        send_buf(fd_client,msg,sendlen);
    }
    //send 0 to client?
}
