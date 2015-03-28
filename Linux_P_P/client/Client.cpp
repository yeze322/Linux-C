#include "common.h"

int main()
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
    return fd_client;
}
