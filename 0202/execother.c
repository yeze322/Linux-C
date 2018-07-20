/*************************************************************************
	> File Name: execother.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 09:35:27 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	printf("pid==%d\n",getpid());
	char *arglist[]={"./showargs","./showargs","hello","world",NULL};
//	execl("./showargs","./showargs","hello","world",NULL);
	execv(arglist[0],arglist);
	printf("exec fail\n");
}

