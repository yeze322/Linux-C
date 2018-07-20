/*************************************************************************
	> File Name: showargs.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 09:33:17 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
	printf("pid = %d\n",getpid());
	int i;
	for(i=0;i<argc;i++)
		printf("%d====%s\n",i,argv[i]);
}
