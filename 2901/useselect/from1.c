/*************************************************************************
  > File Name: 1select.c
  > Author: YeZe
  > Mail:2295905420@qq.com 
  > Created Time: Thu 29 Jan 2015 08:51:09 UTC
 ************************************************************************/
#include"1sel.h"
int main(int argc,char *argv[])
{
	int fd21,fd31;
	char buf[1024]="";
	printf("try to open 1\n");
	fd21=open("./1",O_RDONLY);
	printf("1 open suceess\n");
	fd31=open("./2",O_RDONLY);
	printf("2 open sucess!");
	while(1)
	{
		memset(buf,0,1024);
		write(fd21,buf,strlen(buf));
		if(strcmp(buf,"")!=0)
			printf("from 1: %s",buf);
		memset(buf,0,1024);
		write(fd31,buf,strlen(buf));
		if(strcmp(buf,"")!=0)
			printf("from 2: %s",buf);
	}
	printf("end of program.\n");
	close(fd21);
	close(fd31);
}
