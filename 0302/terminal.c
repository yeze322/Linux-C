/*************************************************************************
  > File Name: terminal.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Tue 03 Feb 2015 07:59:28 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/select.h>//连包处理的考虑?

int main(int argc,char *argv[])
{
	int fdwrite=open("./datapipe",O_WRONLY);
	char buf[1024];
	int fdfork[2]={0};
	pipe(fdfork);
	pid_t pid = fork();
	if(pid==0){//child,read from parent,  continiously write data to pipe
		close(fdfork[1]);
		printf("child start\n");
		char message[1024];
		while(1){
			memset(buf,0,1024);
			memset(message,0,1024);
			read(0,buf,1024);
			sprintf(message,"%s: %s",argv[1],buf);
			write(fdwrite,message,1024);
			printf("child in terminal,send buf %s",message);		
		}
	}else{
		close(fdfork[0]);
		printf("now parent\n");
		int fdread=open(argv[1],O_RDONLY);
		//parent , read from server
		while(1){
			memset(buf,0,1024);
			read(fdread,buf,1024);
			if(strcmp(buf,"")!=0)
				printf("server trans: %s");
		}
	}
}
