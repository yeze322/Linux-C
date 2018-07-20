/*************************************************************************
	> File Name: pipe1.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Wed 28 Jan 2015 12:23:08 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

//send
int main(int argc ,char *argv[])//p1->p2 then p1<-p2
{
	int fdsend=open(argv[1],O_WRONLY);
	int fdrecv=open(argv[2],O_RDONLY);
	if(fdsend==-1||fdrecv==-1)
	{
		perror("set:");
		exit(1);
	}
	printf("patiemt's Connect Succes!!\n");
	char buf[1024];
	while(memset(buf,0,1024),read(0,buf,1024)!=0)
	{
		write(fdsend,buf,strlen(buf));
		memset(buf,0,1024);
		read(fdrecv,buf,1024);
		printf("docotr says:%s\n",buf);
		printf("patient---now say something:\n");
	}
	close(fdsend);
	printf("end");
	close(fdrecv);
	return 0;
}
