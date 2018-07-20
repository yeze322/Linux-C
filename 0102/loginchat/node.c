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
	int login=open("./login",O_WRONLY);
	if(login==-1){
		perror("no login，makesure .//login exsist\n");
		exit(1);
	}
	char buf[1024]="";
	fd_set read_sets;
	printf("connect suc!\n");
/*	char loginkey[100]="I'm on";
	write(fdwr,loginkey,strlen(loginkey));*/
	write(login,argv[1],strlen(argv[1]));
//	close(login);
	int retu;
ag:
	FD_ZERO(&read_sets);
	FD_SET(0,&read_sets);
	FD_SET(fdwr,&read_sets);
	retu=select(1024,&read_sets,NULL,NULL,NULL);
	if(retu)
	{
		if(FD_ISSET(fdwr,&read_sets))
		{
			memset(buf,0,1024);
			read(fdwr,buf,1024);
			if(strcmp(buf,"EOF")==0)
			{
				printf("host poweroff!\n");
				close(fdwr);
				exit(1);
			}
			printf("%s",buf);
		}
		if(FD_ISSET(0,&read_sets))
		{
			memset(buf,0,1024);//input is active, pipe should be write
			read(0,buf,1024);
			if(strcmp(buf,"")==0){
				write(fdwr,"EOF\0",4);
				close(fdwr);
				exit(1);
			}
		//	fflush(stdin);
			char sendbuf[1024];
		/*	strcpy(sendbuf,argv[1]);
			strcat(sendbuf,": ");
			strcat(sendbuf,buf);*/
			sprintf(sendbuf,"%s: %s",argv[1],buf);
			write(fdwr,sendbuf,strlen(sendbuf));
			printf("			zzzzzz\n");
			usleep(10000);//改变位置，优化延迟
		}
	}
	goto ag;
}
