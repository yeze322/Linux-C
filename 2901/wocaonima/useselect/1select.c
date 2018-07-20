/*************************************************************************
  > File Name: 1select.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Thu 29 Jan 2015 08:51:09 UTC
 ************************************************************************/
#include"1sel.h"
int main(int argc,char *argv[])
{
	int fd21,fd31,fd12,fd13;

	fd13=open(argv[1],O_WRONLY);
	printf("1 to 3 ok,,,fd13=   %d   \n",fd13);
	fd12=open(argv[2],O_WRONLY);
	printf("1 to 2 ok,,,,,,fd12 = %d\n",fd12);
	fd21=open(argv[3],O_RDONLY);
	printf("1 from 2 ok\n");
	fd31=open(argv[5],O_RDONLY);
	printf("1 from 3 ok\n");
	printf("connect success!\n");
	useselect(fd21,fd31,fd12,fd13);
	close(fd21);
	close(fd31);
	close(fd12);
	close(fd13);
	printf("end of program.\n");
}
