/*************************************************************************
  > File Name: thread.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Thu 29 Jan 2015 07:03:47 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>


void* thread_fun1(void* arge); //创建第一个线程时执行该函数
void* thread_fun2(void* arge); //创建第二个线程时执行该函数
void* thread_fun3(void* arge); //创建第二个线程时执行该函数

int fdrecv1;
int fdrecv2;
int fdrecv3;

int main(int argc, char* argv[], char* env[])
{
	fdrecv1=open(argv[1],O_RDONLY);
	fdrecv2=open(argv[2],O_RDONLY);
	fdrecv3=open(argv[3],O_RDONLY);

	printf("char begin....\n");
	pthread_t pthread_id1, pthread_id2,pthread_id3;

	pthread_create(&pthread_id1, NULL, (void*)&thread_fun1, NULL);
	pthread_create(&pthread_id2, NULL, (void*)&thread_fun2, NULL);
	pthread_create(&pthread_id3, NULL, (void*)&thread_fun3, NULL);

	/*while(1)
	  {
	  memset(buf,0,1024);
	  if(read(fdrecv1,buf,1024))
	  printf("%s\n",buf);

	  memset(buf,0,1024);
	  if(read(fdrecv2,buf,1024))
	  printf("%s\n",buf);

	  memset(buf,0,1024);
	  if(read(fdrecv3,buf,1024))
	  printf("%s\n",buf);
	  }*/



	pthread_exit(NULL);

	close(fdrecv1);
	close(fdrecv2);
	close(fdrecv3);

}

void* thread_fun1(void* arge)
{
	char buf1[1024];
	printf("This is thread function1.\n"); //输出语句1
	while(memset(buf1,0,1024),read(fdrecv1,buf1,1024)!=-1){
		printf("%s",buf1);
	}
	printf("end----thread1\n");
	pthread_exit(NULL);
}

void* thread_fun2(void* arge)
{
	char buf2[1024];
	printf("This is thread function1.\n"); //输出语句1
	while(memset(buf2,0,1024),read(fdrecv2,buf2,1024)!=-1){
		printf("%s",buf2);
	}
	printf("end----thread2\n");
	pthread_exit(NULL);
}

void* thread_fun3(void* arge)
{
	char buf3[1024];
	printf("This is thread function1.\n"); //输出语句1
	while(memset(buf3,0,1024),read(fdrecv3,buf3,1024)!=-1){
		printf("%s",buf3);
	}
	printf("end----thread3\n");
	pthread_exit(NULL);
}

