/*************************************************************************
	> File Name: pool.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Thu 29 Jan 2015 03:09:15 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fdrecv1=open(argv[1],O_RDONLY);
	int fdrecv2=open(argv[2],O_RDONLY);
	int fdrecv3=open(argv[3],O_RDONLY);
	char buf[1024];
	printf("char begin....\n");

	while(1)
	{
		memset(buf,0,1024);
	if(read(fdrecv1,buf,1024))
		printf("%s\n",buf);
		
		memset(buf,0,1024);
	if(read(fdrecv2,buf,1024))
		printf("%s\n",buf);
		
		memset(buf,0,1024);
	if(read(fdrecv3,buf,1024))
		printf("%s\n",buf);
	}
	close(fdrecv1);
	close(fdrecv2);
	close(fdrecv3);
}
