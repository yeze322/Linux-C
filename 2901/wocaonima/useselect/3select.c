/*************************************************************************
  > File Name: 3select.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Thu 29 Jan 2015 08:51:09 UTC
 ************************************************************************/
#include "3sel.h"
int main(int argc,char *argv[])
{
	int fd23,fd31,fd32,fd13;

	fd13=open(argv[2],O_RDONLY);
	printf("3 from 1 ok\n");
	fd23=open(argv[4],O_RDONLY);
	printf("2 to 3 ok\n");
	fd31=open(argv[5],O_WRONLY);
	printf("3 to 1 ok\n");
	fd32=open(argv[6],O_WRONLY);
	printf("2 from 3 ok\n");
	printf("connect success!\n");
	char buf[1024]="";
	while(1)
	{
		memset(buf,0,1024);
		read(fd13,buf,1024);
		printf("%S",buf);
	}
//	useselect(fd23,fd31,fd32,fd13);
	close(fd23);
	close(fd31);
	close(fd32);
	close(fd13);
	printf("end of program.\n");
}
