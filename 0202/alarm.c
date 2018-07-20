/*************************************************************************
	> File Name: alarm.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 14:27:40 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
static int alarm_fired = 0;
void ding(int sig)
{
	alarm_fired=1;
}

int main()
{
	pid_t child;
	printf("alarm begin\n");
	child = fork();
	if(child==-1)
	{
		printf("fork fail\n");
		exit(1);
	}else if(child==0){
		sleep(5);
		kill(getppid(),SIGALRM);
		exit(0);
	}
	printf("waiting for alarm...\n");
	pause();
	if(alarm_fired)
		printf("ding\n!");
	printf("done\n");
	exit(0);
}
