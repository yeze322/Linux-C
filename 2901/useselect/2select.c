/*************************************************************************
  > File Name: 2select.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Thu 29 Jan 2015 08:51:09 UTC
 ************************************************************************/
#include "sel0.h"
int main(int argc,char *argv[])
{
	int fd21,fd32,fd12,fd23;

	fd12=open(argv[1],O_RDONLY);
	printf("2 from 1 ok\n");
	fd21=open(argv[3],O_WRONLY);
	printf("2 to 1 ok\n");
	fd23=open(argv[4],O_WRONLY);
	printf("2 to 3 ok\n");
	fd32=open(argv[6],O_RDONLY);
	printf("3 from 2 ok\n");
	printf("connect success!\n");
	useselect(fd12,fd32,fd21,fd23);
	close(fd21);
	close(fd32);
	close(fd12);
	close(fd23);
	printf("end of program.\n");
}
