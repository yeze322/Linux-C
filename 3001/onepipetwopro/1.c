/*************************************************************************
  > File Name: 1.c
  > Author: YeZe
  > Mail:a@b.com 
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
	printf("pro start_%d_%s\n",argc,argv[1]);
	int fdwr=open(argv[1],O_RDWR);
	char buf[1024]="";
	fd_set read_sets;
	printf("connect suc!\n");
	int retu;
ag:
	FD_ZERO(&read_sets);
	FD_SET(0,&read_sets);
	FD_SET(fdwr,&read_sets);
	printf("pipe active? %d\n",FD_ISSET(fdwr,&read_sets));
	retu=select(1024,&read_sets,NULL,NULL,NULL);
	if(retu)
	{
		if(FD_ISSET(fdwr,&read_sets))
		{
			printf("pipe active !\n");
			memset(buf,0,1024);
			read(fdwr,buf,1024);
			if(strcmp(buf,"EOF")==0)
			{
				close(fdwr);
				exit(1);
			}
			printf("%s",buf);
		}
		if(FD_ISSET(0,&read_sets))
		{
			printf("input active \n");
			memset(buf,0,1024);//input is active, pipe should be write
			read(0,buf,1024);
			write(fdwr,buf,strlen(buf));
			if(strcmp(buf,"")==0){
				write(fdwr,"EOF",5);
				close(fdwr);
				exit(1);
			}
			fflush(stdin);
		}
		sleep(1);
	}
	goto ag;
}
