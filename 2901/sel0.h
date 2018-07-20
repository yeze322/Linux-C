/*************************************************************************
  > File Name: sel.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Thu 29 Jan 2015 14:35:26 UTC
 ************************************************************************/

#include<stdio.h>
#include<sys/select.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/types.h>

void useselect(int a,int b,int c,int d)
{
	printf("select begin!\n");
	char buf[1024];			printf("buf create\n");
//	struct timeval tm;
fg:
//	tm.tv_sec=5;//for delay
//	tm.tv_usec=0;

	fd_set read_sets;		printf("fd_set create\n");
	FD_ZERO(&read_sets);//like memset
	printf("line 28\n");
	FD_SET(a,&read_sets);
	printf("line 31\n");
	FD_SET(b,&read_sets);
	printf("line 33\n");
	FD_SET(c,&read_sets);
	printf("line 35\n");
	FD_SET(d,&read_sets);
	printf("line 37\n");
	//select is a block function
	memset(buf,0,1024);

	printf("write finish! buf =[%s]\n",buf);
	//t select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);	
	int  retu;
	printf("start select!\n");
	retu=select(1024,&read_sets,NULL,NULL,NULL);//NULL means keep wait
	printf("select finish!\n");
	//read_sets is  out also input
	/*	if(retu==0)
		{
		printf("no active!\n");
		}
		else if(retu==-1)
		{
		return;
		}else*/
	int flag=0;
	//now visit the set, FDSET has only two elements,
	////just see who is in,
	if(retu){
		printf("begin if 1!\n");
		if(FD_ISSET(a,&read_sets))
		{
			memset(buf,0,1024);
			if(read(a,buf,1023)==0)
				flag++;
			if(strcmp(buf,"")!=0)
				printf("2 said---:%s\n",buf);
		}
		printf("another if!\n");
		if(FD_ISSET(b,&read_sets))
		{
			memset(buf,0,1024);
			if(read(b,buf,1023)!=0)
				printf("3 said---:%s\n",buf);
			else
				flag++;
		}
		if(FD_ISSET(c,&read_sets)||FD_ISSET(d,&read_sets))
		{
			if(read(0,buf,1023)!=0)
				write(d,buf,strlen(buf));
			write(c,buf,strlen(buf));
			printf("read something  \n");
			else
				printf("read no!!!\n");

		}
		if(flag==2)
		{
			printf("noinput");
			exit(1);
		}
	}
	printf("this loop is end!\n");
	goto fg;
}

