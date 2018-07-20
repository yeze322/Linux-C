/*************************************************************************
	> File Name: 3.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Fri 30 Jan 2015 02:05:58 UTC
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int f1=open(argv[1],O_WRONLY);
	printf("openag suc!\n");
	char buf[1024];
	while(memset(buf,0,1024),read(0,buf,1024)!=0)
	{
		write(f1,buf,strlen(buf));
	}
	close(f1);
	printf("end!");
}
