/*4************************************************************************
  > File Name: pipe2.c
  > Author: YeZe
  > Mail:a@b.com 
  > C: Wed 28 Jan 2015 12:23:08 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

//send
int main(int argc ,char *argv[])//1to2 1to3 2to1 | 2to3 3to1 3to2
{
	putchar("20");
	int fdrecv1=open(argv[1],O_RDONLY);
	putchar("2--1");
	int fdsend1=open(argv[3],O_WRONLY);
	int fdsend2=open(argv[4],O_WRONLY);
	int fdrecv2=open(argv[6],O_RDONLY);
	if(fdsend1==-1||fdrecv1==-1||fdrecv2==-1)
	{
		perror("set:");
		exit(1);
	}
	printf("patiemt's Connect Succes!!\n");
	char buf[1024];
	while(1)
	{
		memset(buf,0,1024);
		printf("patient---now say something:\n");
		if(read(0,buf,1024)!=0)
		{
			write(fdsend1,buf,strlen(buf));
			write(fdsend2,buf,strlen(buf));
		}
		memset(buf,0,1024);
		read(fdrecv1,buf,1024);
		if(strcmp(buf,"")!=0)
			printf("[docotr says]:%s\n",buf);
		memset(buf,0,1024);
		read(fdrecv2,buf,1024);
		if(strcmp(buf,"")!=0)
			printf("[hugo says]:%s\n",buf);

	}
	Close(fdsend1);
	Close(fdsend2);
	printf("end");
	close(fdrecv1);
	close(fdrecv2);
	return 0;
}
