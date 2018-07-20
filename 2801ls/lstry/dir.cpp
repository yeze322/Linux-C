/*************************************************************************
  > File Name: class.cpp
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Wed 28 Jan 2015 07:11:01 UTC
 ************************************************************************/

//#include<iostream>
//using namespace std;
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc ,char *argv[])
{//这个的功能应该是列出某个路径下所有目录信息
	DIR *fp_dir;
	struct dirent* pent;
	//chdir("..");
	fp_dir=opendir(argv[1]);
	assert(fp_dir!=NULL);
/*	if(fp_dir == NULL)
	{
		perror("open");
		exit(1);
	}*/
	while((pent=readdir(fp_dir))!=NULL)
	{
		printf("-------------------\n");
		printf("ino:%u \noff_t:%u\nrec:%u\nname:%u\n",\
				pent->d_ino,pent->d_off,pent->d_reclen,pent->d_name);
	}


	printf("OK\n");
	return 0;
}

