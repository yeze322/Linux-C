/*************************************************************************
	> File Name: progress.c
	> Author: YeZe
	> Mail:2295905420@qq.com 
	> Created Time: Mon 02 Feb 2015 08:21:34 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int ret = system(argv[1]);
	printf("ret = %04x\n",ret);
	return 0;
}
