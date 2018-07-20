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
	char buf[1024];		
	int  retu;
	int flag=0;
	
	int my_stdin;

	dup2(0,my_stdin);

	fd_set read_sets;	
fg:	FD_ZERO(&read_sets);//like memset
	FD_SET(a,&read_sets);
	FD_SET(b,&read_sets);
	FD_SET(my_stdin,&read_sets);
	memset(buf,0,1024);
	
	retu=select(1024,&read_sets,NULL,NULL,NULL);//NULL means keep wait
	printf("select end\n");
	flag =0;

	if(retu){
printf("%d--%d\n",FD_ISSET(a,&read_sets),FD_ISSET(b,&read_sets));
		if(FD_ISSET(a,&read_sets))
		{
			memset(buf,0,1024);
			if(read(a,buf,1023)==0)
				flag++;
			if(strcmp(buf,"")!=0)
				printf("2 said---:%s\n",buf);
		}
		if(FD_ISSET(b,&read_sets))
		{
			memset(buf,0,1024);
			if(read(b,buf,1023)!=0)
				printf("3 said---:%s\n",buf);
			else
				flag++;
		}
		if(FD_ISSET(0,&read_sets))
		{
			memset(buf,0,1024);
			read(my_stdin,buf,1024);
			if(strcmp(buf,"")==0)
			{
				close(d);
				close(c);
				printf("DD");
				exit(1);
			}
			write(d,buf,strlen(buf));
			write(c,buf,strlen(buf));
			printf("read something and write finish \n");

		}
	
		if(flag==2)
		{
			printf("noinput");
			close(a);
			close(c);
			close(d);
			close(b);
			exit(1);
		}
	}

	goto fg;
}

