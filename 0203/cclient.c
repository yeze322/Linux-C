/*************************************************************************
> File Name: client.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年03月02日 星期一 11时58分24秒
************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
char* SER_IP;
#define SER_PORT 1234
void per(int a){if(a == -1){perror("-1\n");exit(1);}}
void pstr(char *str){printf("%s\n",str);}
void send_main(int fd_client,char *);
void save(int fd_client);
int sock_connet();

void command_analyse(int fd_client,char *command)
{
    char *yourfile;
    command[strlen(command)-1]='\0';
    yourfile = strstr(command,"@");
    if(yourfile==NULL)
    return;
    *yourfile = '\0';
    /*shake hand three times!*/

    yourfile++;
    if(strcmp(command,"upload")==0||strcmp(command,"u")==0){
        send(fd_client,command,strlen(command),0);
        while(recv(fd_client,command,strlen(command),0)==0)
        ;
        send_main(fd_client,yourfile);
    }
    if(strcmp(command,"d")==0||strcmp(command,"download")==0){
        send(fd_client,command,strlen(command),0);
        while(recv(fd_client,command,1,0)==0)
        ;
        send(fd_client,yourfile,strlen(yourfile),0);
        save(fd_client);
    }
}

int main(int argc, char *argv[])
{   
    SER_IP = argv[1];
    int fd_client = sock_connet();
    char command[100];
    printf("[example: upload@./filename.c]\n");
    while(1){
        memset(command,0,100);
        printf("input command:\n");
        if(read(0,command,99)==0) {
            send(fd_client,"EOF",4,0);
            printf("unavailable command\n");
            break;
        }
        command_analyse(fd_client,command);
        printf("finish command!\n\n");
    }
    close(fd_client);
    return 0;
}

int sock_connet()
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

void send_main(int fd_client,char *yourfile)
{
    printf("you want to send: %s\n",yourfile);
    /* now finish analyse. */
    //send 
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
        printf("%d+",recvnum);
        fwrite(p,1,recvnum,fp_recv);
        if(recvnum<1024)
        break;
    }
    fclose(fp_recv);
    close(fd);
    printf("\nrecv finishi\n");
    send(fd_client,fileName,1,0);
    /* shake hand */
}
