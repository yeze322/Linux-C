/*************************************************************************
  > File Name: myls.c
  > Author: YeZe
  > Mail:a@b.com 
  > Created Time: Wed 28 Jan 2015 09:04:19 UTC
 ************************************************************************/

//#include<stdio.h>

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
#include<grp.h>
#include<pwd.h>
#include<time.h>
#include<sys/stat.h>

void mode_to_str(mode_t md, char* buf) ;


void show_info(char*path)//print one files info
{
	struct stat my_stat;
	memset(&my_stat,0,sizeof(my_stat));
	if(-1==stat(path,&my_stat))
	{perror("stat");exit(1);}//error judge
	char buf[11];//save the rwx---
	mode_to_str(my_stat.st_mode,buf);
	char timecut[20]="";
	strncpy(timecut,ctime(&my_stat.st_mtime)+4,12);
	printf("%s.%2d %s %s%5d %s %s\n",	buf,my_stat.st_nlink,\
			getpwuid(my_stat.st_uid)->pw_name,\
			getgrgid(my_stat.st_gid)->gr_name,\
			my_stat.st_size,timecut,path
		  );//print basic info
}
int cmp(const void *left,const void *right)
{
	struct dirent* a=*((struct dirent**)left);
	struct dirent* b=*((struct dirent**)right);
	return strcmp(a->d_name,b->d_name);
}


int main(int argc ,char *argv[])
{//这个的功能应该是列出某个路径下所有目录信息
	DIR *fp_dir;
	struct dirent* pent[30];
	//chdir("..");
	fp_dir=opendir(argv[1]);
	assert(fp_dir!=NULL);
	/*	if(fp_dir == NULL)
		{
		perror("open");
		exit(1);
		}*/
	//show_info(".");
//	show_info("..");
	int i=0;
	while((pent[i]=readdir(fp_dir))!=NULL)
	{
		//	printf("-------------------\n");
		//printf("ino:%u \noff_t:%u\nrec:%u\nname:%u\n",\
		pent->d_ino,pent->d_off,pent->d_reclen,pent->d_name);
		i++;		}
	qsort(pent,i,sizeof(struct dirent*),cmp);
	int j;
	for(j=0;j<i;j++)
		show_info(pent[j]->d_name);

	closedir(fp_dir);
	return 0;
}


void mode_to_str(mode_t md, char* buf) 
{
	if(S_ISREG(md))
	{
		buf[0] ='-' ;
	}else if(S_ISDIR(md))
	{
		buf[0] ='d';
	}else if(S_ISCHR(md))
	{
		buf[0] = 'c' ;
	}else if(S_ISBLK(md))
	{
		buf[0]='b';
	}else if(S_ISFIFO(md))
	{
		buf[0] = 'p';
	}else if(S_ISLNK(md))
	{
		buf[0] = 'l' ;
	}else 
	{
		buf[0] = 's' ;
	}
	if(md & S_IRUSR)
	{
		buf[1] = 'r' ; 
	}else 
	{
		buf[1] = '-' ;
	}

	if(md & S_IWUSR)
	{
		buf[2] = 'w' ; 
	}else 
	{
		buf[2] = '-' ;
	}

	if(md & S_IXUSR)
	{
		buf[3] = 'x' ; 
	}else 
	{
		buf[3] = '-' ;
	}


	if(md & S_IRGRP)
	{
		buf[4] = 'r' ; 
	}else 
	{
		buf[4] = '-' ;
	}

	if(md & S_IWGRP)
	{
		buf[5] = 'w' ; 
	}else 
	{
		buf[5] = '-' ;
	}

	if(md & S_IXGRP)
	{
		buf[6] = 'x' ; 
	}else 
	{
		buf[6] = '-' ;
	}

	if(md & S_IROTH)
	{
		buf[7] = 'r' ; 
	}else 
	{
		buf[7] = '-' ;
	}

	if(md & S_IWOTH)
	{
		buf[8] = 'w' ; 
	}else 
	{
		buf[8] = '-' ;
	}
	if(md & S_IXOTH)
	{
		buf[9] = 'x' ; 
	}else 
	{
		buf[9] = '-' ;
	}
	buf[10] = 0;

}
