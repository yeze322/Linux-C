
/*************************************************************************
  > File Name: host.c
  > Author: YeZe
  > Mail:2295905420@qq.com 
  > Created Time: Fri 30 Jan 2015 03:05:58 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>//read
#include<fcntl.h>
#include<sys/types.h>//open
#include<string.h>
#include<sys/select.h>
#include<time.h>

int main(int argc,char *argv[])
{
	printf("host start__\n");
	int fd1=open(argv[1],O_RDWR);
	char buf[1024]="";
	fd_set read_sets;
	printf("connect suc!\n");
ag:	FD_ZERO(&read_sets);
	FD_SET(fd1,&read_sets);
	FD_SET(0,&read_sets);

	int retu=select(1024,&read_sets,NULL,NULL,NULL);
	if(retu){
		if(FD_ISSET(fd1,&read_sets))//data in pipe
		{
			memset(buf,0,1024);
			read(fd1,buf,1024);
			printf("%s",buf);
			if(strcmp(buf,"")==0){
				printf("no input!\n");
				exit(1);
			}
		}
		if(FD_ISSET(0,&read_sets))
		{
			memset(buf,0,1024);
			if(read(0,buf,1024)!=0)
				write(fd1,buf,strlen(buf));
			else{
				printf("end!\n");
				exit(1);
			}
		}
		sleep(1);
	}
	goto ag;
}
