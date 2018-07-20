/*************************************************************************
	> File Name: pipe2.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Wed 28 Jan 2015 12:23:18 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc ,char *argv[])//p2<-p1, then p2->p1
{
	int fdrecv=open(argv[1],O_RDONLY);
	int fdsend=open(argv[2],O_WRONLY);
	if(fdsend==-1||fdrecv==-1)
	{
		perror("set:");
		exit(1);
	}
	char buf[1024];
	printf("doctor's Connect Sucess!\n");
	while(memset(buf,0,1024),read(fdrecv,buf,1024)!=0)
	{
		printf("teacher says:%s\n",buf);
		memset(buf,0,1024);
		printf("doctoe---now say something:_\n");
		read(0,buf,1024);
		write(fdsend,buf,1024);
	}
	printf("end");
	close(fdrecv);
	close(fdsend);
	return 0;
}

//./a.out fifo两端必须都有程序
