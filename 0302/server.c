/*************************************************************************
  > File Name: server.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Tue 03 Feb 2015 07:10:57 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/select.h>//连包处理的考虑?
#define N 100
int main(int argc,char *argv[])
{
	int fd[N]={0};
	char buf[1024];
	int data=open("./datapipe",O_RDONLY);
	int fds[2]={0};
	pipe(fds);
	pid_t pid = fork();
	if(pid==0){//child,read from terminal,write to parent
		close(fds[0]);
		printf("child\n");
		char message[1024]="";
		while(1){
			memset(buf,0,1024);
			read(data,buf,1024);//remember to treat the char here
			//transfer data to readable meesage)
			printf("read suc! %s",buf);
			write(fds[1],buf,1024);
		}
	}else{//parent, write to all terminals, read from child
		close(fds[1]);//close write
		printf("parent\n");
		int i;
		for(i=1;i<argc;i++)
			fd[i]=open(argv[i],O_WRONLY);
		while(1){
			memset(buf,0,1024);
			read(fds[0],buf,1024);
			for(i=1;i<argc;i++)
				write(fd[i],buf,1024);
		}
	}

}
