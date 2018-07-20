/*****
  > File Name: input.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Sun 01 Feb 2015 09:25:17 UTC
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd[20]={0};
	int i;
	FILE *fp=fopen("./host.c","r");

	for(i=1;i<argc;i++)
		fd[i]=open(argv[i],O_WRONLY);
	char buf[1024];
	while(1){
		memset(buf,0,1024);
		fgets(buf);		  
		//random write add
			write(fd[i],buf,strlen(buf));
			usleep(500);
		}
	}
}
