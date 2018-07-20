/*************************************************************************
	> File Name: p1.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Thu 29 Jan 2015 02:57:07 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])//1to 2to 3to pool
{
	int fdsend=open(argv[1],O_WRONLY);
//	int fdrecv(argv[4],O_RDONLY);
	printf("[%d]",fdsend);
	if(fdsend==-1)//||fdrecv==-1)
	{
		perror("open failed!\n");
		exit(1);
	}
	printf("success!\n");
	char buf[1024];
	while(memset(buf,0,1024),strcpy(buf,"p1: "),read(0,buf+4,1020)!=-1){
		write(fdsend,buf,strlen(buf));
	}
	close(fdsend);
	//close(fdrecv);
}
