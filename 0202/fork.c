/*************************************************************************
	> File Name: fork.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 09:08:33 UTC
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//files
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	int a=2015;
	int fd = open("./1.txt",O_RDONLY);
	pid_t pid;
	pid = fork();
	if(pid>0)//means father
	{	
		printf("fork ret:  %d, [a]=%d\n",pid,++a);
		printf("parent....pid:%d----=ppid :%d\n",getpid(),getppid());
	}
	else if (pid == 0)//means child
	{	
		printf("\nfork ret:  %d,[a]=%d\n",pid,a);
		printf("child.... pid:%d----=ppid :%d\n",getpid(),getppid());
	}
	printf("common statment\n");
	return 0;
}
