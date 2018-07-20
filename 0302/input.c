/*************************************************************************
	> File Name: input.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Tue 03 Feb 2015 08:49:09 UTC
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
	int fdwrite1=open(argv[1],O_WRONLY);
	int fdwrite2=open(argv[2],O_WRONLY);
	char buf[1024];
	while(1)
	{
		memset(buf,0,1024);
		read(0,buf,1024);
		if(fork()==0){
			printf("child\n");
			write(fdwrite1,buf,1024);
			printf("child write pipe1 success\n");
			exit(0);
		}
		else{
			printf("parent\n");
			write(fdwrite2,buf,1024);
			printf("parent write pipe2 success\n");			
			wait(NULL);
		}
		printf("done\n");
	}
}
