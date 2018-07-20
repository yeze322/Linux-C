/*************************************************************************
	> File Name: 2.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Fri 30 Jan 2015 01:32:01 UTC
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int f1=open(argv[1],O_RDONLY);
	printf("open suc!\n");
	char buf[1024];
	getchar();
	while(1)
	{
		memset(buf,0,1024);
		read(f1,buf,1024);
		printf("%s",buf);
	}
}
