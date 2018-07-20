/*************************************************************************
	> File Name: getuid.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 07:03:22 UTC
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pwd.h>
void fun()
{
	printf("hellsaod\n");
}
int main()
{
	atexit(&fun);
//	printf("uid--%s\ngid--%d\n",getpwuid(getuid())->pw_name,getgid());
	printf("helloworld!11111\n");
//	exit(1);
//	fflush(stdout);
	while(1);
}
