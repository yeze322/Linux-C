
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
#include<sys/time.h>
#define N 100
void waitfornode(int *fd,int n,fd_set);
void writenfifo(char buf[],int n,int *fd,int i,fd_set *);
int main(int argc,char *argv[])//用argc来创建一个数组
{
	int fd[N]={0},i;
	char *exitbuf="EOF";
	int login=open("./login",O_RDONLY);
	if(login==-1){
		perror("no login file,makesure .//login exsist\n");
		exit(1);
	}
	/*
	for(i=1;i<argc;i++)
	{
		printf("add pipe[%d]\n",i);
		fd[i]=open(argv[i],O_RDWR);
	}*/
	char buf[1024]="";
	char loginkey[15]="I'm on";
	fd_set read_sets,examactive;
	struct timeval st;
	st.tv_sec=0;
	st.tv_usec=100;//100ms wait
	int active=0;
	int retu;//exitflag---退出常数，累积到一定值就会触发服务器的终止。//先不添加这个功能吧
ag:
	FD_ZERO(&read_sets);
	//	FD_ZERO(&examactive);
	FD_SET(0,&read_sets);
	FD_SET(login,&read_sets);
	for(i=1;i<=active;i++){
		FD_SET(fd[i],&read_sets);
		//		FD_SET(fd[i],&examactive);
	}
	retu=select(1024,&read_sets,NULL,NULL,NULL);
	//new set to examine all the pipes, i think sleep is more useable than this
	if(retu)
	{
		for(i=1;i<=active;i++)
		{
			printf("detect all node...%d\n",active);
			if(FD_ISSET(fd[i],&read_sets))
			{
				printf("find the active one [%d]\n",i);
				memset(buf,0,1024);
				read(fd[i],buf,1024);
				if(strcmp(buf,"EOF")==0){
					close(fd[i]);
					fd[i]=0;//用链表比较好
					int writ=1;
					for(i=1;i<=active;i++)
					{
						if(fd[i]!=0)
							fd[writ++]=fd[i];
					}
					active--;
					printf("terminal[%d] is off line...\n",i);
				}else{
					printf("start write...\n");
					writenfifo(buf,active,fd,i,&read_sets);
					printf("[%d],%s",i,buf);
					//	FD_CLR(fd[i],&examactive);
				}
				break;
			}//去掉break，因为会并发的情况.但是先不考虑这个吧
		}
		//	while(select(1024,&examactive,NULL,NULL,&st));
		if(FD_ISSET(0,&read_sets))
		{
			printf("input active \n");
			memset(buf,0,1024);//input is active, pipe should be write
			read(0,buf,1024);
			if(strcmp(buf,"")==0){
				writenfifo(exitbuf,active,fd,0,&read_sets);
				exit(1);
			}
			writenfifo(buf,active,fd,0,&read_sets);
			//	while(select(1024,&examactive,NULL,NULL,&st));
		}
		if(FD_ISSET(login,&read_sets))
		{//some user is online
			char user[100]="";
			read(login,user,100);
			if(strcmp(user,"")==0)
				goto ag;
			printf("login is active,");
			printf("username :[%s]\n",user);
			//want to use queue to save those logins
			for(i=1;i<=N;i++){
				if(fd[i]==0){
					active++;
					break;
				}
			}
			fd[i]=open(user,O_RDWR);
			printf("fd[%d],[%s] is online...",i,user);
		}

		//	printf("sleep is active...\n");
		usleep(10000);

	}
	goto ag;
}
void waitfornode(int *fd,int n,fd_set read_sets)
{
	int noactive,j,loop=0;
	do{
		loop++;
		if(loop==5){
			printf("error!\n");
			sleep(100);//for debug
		}
		putchar('!');
		noactive=0;
		for(j=1;j<n;j++)
			printf("fd[%d]--if?%d\n",j,FD_ISSET(fd[j],&read_sets));
		for(j=1;j<n&&noactive!=1;j++)
			noactive=noactive||FD_ISSET(fd[j],&read_sets);
		printf("still active? %d\n",noactive);
	}while(noactive);
	//make sure all node has finish read
}
void writenfifo(char buf[],int n,int *fd,int except,fd_set *read_sets)
{//0端作为保留端没有占用，except为0就是全员写 this is not smart
	//use abig number is better!
	int i;
	printf("\n		start lopp write[buf=%s;\
			n=%d,except=%d]\n",buf,n,except);
	for(i=1;i<=n;i++)
	{
		if(i==except)
			continue;
		printf("------------loop %d act?%d\n",i,FD_ISSET(fd[i],read_sets));
		write(fd[i],buf,strlen(buf));
		//		FD_CLR(fd[i],read_sets);
		//写完后从本次周期删除是个好习惯啊，不然会一直活动的再加上1阻塞那就更阻塞了
	}
}
