/*************************************************************************
  > File Name: test.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Mon 02 Feb 2015 15:28:53 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid==-1){
		perror("fork fail\n");
		exit(1);

	}else if(pid ==0 ){
		int i=100;
		while(i--){
			sleep(1);
			printf("child\n");
		}
	}else{
		while(1){
			sleep(1);
			printf("parent\n");
		}
	}
	printf("done\n");
	exit(0);
}
