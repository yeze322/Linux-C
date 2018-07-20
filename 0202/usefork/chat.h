/*************************************************************************
	> File Name: chat.h
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 15:13:40 UTC
 ************************************************************************/

//#include<iostream>
//using namespace std;

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
void child(int fdread)
{
	printf("child activate\n");
	char buf[1024];
	while(1)
	{
		memset(buf,0,1024);
		printf("read start\n");
		read(fdread,buf,1024);
		if(strcmp(buf,"EOF")==0)
		{
			printf("chile end\n");
			close(fdread);
			return;
		}
		if(strcmp(buf,"")!=0)
			printf("from: %s",buf);
	}
}
void parent(int fdwrite)
{
	printf("parent activate\n");
	char buf[1024];
	char *exitbuf="EOF";
	while(1)
	{
		memset(buf,0,1024);
		printf("start stdin\n");
		if(read(0,buf,1024)==0){
			printf("end of file!\n");
			write(fdwrite,exitbuf,strlen(exitbuf));
			sleep(1);
			close(fdwrite);
			return;
		}
		else
			write(fdwrite,buf,strlen(buf));
	}
}
