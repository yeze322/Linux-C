
/*************************************************************************
  > File Name: host.c
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
void writenfifo(char buf[],int n,int *fd,int i);
int main(int argc,char *argv[])//用argc来创建一个数组
{
	printf("pro start_%d_\n",argc);
	int fd[argc],i;
	char *exitbuf="EOF";
	for(i=1;i<argc;i++)
	{
		printf("add pipe[%d]\n",i);
		fd[i]=open(argv[i],O_RDWR);
	}
	char buf[1024]="";
	fd_set read_sets;
	printf("connect suc!\n");
	int retu,exitflag;//exitflag---退出常数，累积到一定值就会触发服务器的终止。//先不添加这个功能吧
ag:
	FD_ZERO(&read_sets);
	FD_SET(0,&read_sets);
	for(i=1;i<argc;i++)
		FD_SET(fd[i],&read_sets);
	printf("select start:\n");
	printf("input active? %d\n",FD_ISSET(0,&read_sets));
	retu=select(1024,&read_sets,NULL,NULL,NULL);
	printf("select end!\n");
	exitflag=0;
	if(retu)
	{
		for(i=1;i<argc;i++)
		{
			printf("detect all node...\n");
			if(FD_ISSET(fd[i],&read_sets))
			{
				printf("find the active one [%d]\n",i);
				memset(buf,0,1024);
				read(fd[i],buf,1024);
				writenfifo(buf,argc-1,fd,i);//后期增加一个区分来源的功能，把信息转发给来源之外的所有
				printf("[%d],%s",i,buf);
				break;
			}
		}
		if(FD_ISSET(0,&read_sets))
		{
			printf("input active \n");
			memset(buf,0,1024);//input is active, pipe should be write
			read(0,buf,1024);
//			write(fdwr,buf,strlen(buf));
			writenfifo(buf,argc-1,fd,0);
			if(strcmp(buf,"")==0){
				writenfifo(exitbuf,argc-1,fd,0);
				exit(1);
			}
		}
	}
	goto ag;
}

void writenfifo(char buf[],int n,int *fd,int except)
{//0端作为保留端没有占用，except为0就是全员写 this is not smart
	//use abig number is better!
	int i;
	for(i=1;i<=n&&i!=except;i++)
		write(fd[i],buf,strlen(buf));
}
