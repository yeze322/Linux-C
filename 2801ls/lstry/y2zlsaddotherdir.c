/*************************************************************************
	> File Name: yzls.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Wed 28 Jan 2015 11:04:15 UTC
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#define N 100

void mode_to_str(mode_t md,char *buf);
void show_info(char *,char*);
int cmp(const void *left,const void *right);


int main(int argc, char *argv[])
{
//	chdir(argc[1]);//!!!add
	DIR *fp_dir=opendir(argv[1]);
	//#include <dirent.h> DIR *opendir(const char *dirname); 
	struct dirent *pent[N];
	if(fp_dir==NULL)
	{
		perror("open");
		exit(1);
	}
	int i=0;
	while((pent[i]=readdir(fp_dir))!=NULL)
	//#include <sys/types.h>#include <dirent.h>
	//struct dirent *readdir(DIR *dir),the defination of 'dirent' is in readdir
	{	i++;	}
	qsort(pent,i,sizeof(struct dirent*),cmp);//sort the path by name
	int j;
	for(j=0;j<i;j++)
		show_info(argv[1],pent[j]->d_name);
	closedir(fp_dir);
	return 0;
}

void show_info(char *base_dir,char *file_name)//change variavble
{

	char path[1024]="";
	sprintf(path,"%s/%s",base_dir,file_name);

	struct stat a;
	memset(&a,0,sizeof(a));
	if(stat(base_dir,&a)==-1)//read path into stat a
	//#include <sys/types.h> #include <sys/stat.h>//#include <unistd.h> 
	//int stat(const char *path, struct stat *buf);
	{
		perror("stat");
		exit(1);
	}	
	char buf[11];//t osave the rxwr--r-- info
	mode_to_str(a.st_mode,buf);//mode_t  st_mode;  /* protection */
	char timecut[20]="";
	strncpy(timecut,ctime(&a.st_mtime)+4,12);
	//char *ctime_r(const time_t *clock, char *buf);
	printf("%s.%2d %s %s %5d %s %s\n",\
			buf,a.st_nlink,\
			//protection and linknum
			getpwuid(a.st_uid)->pw_name,\
			//#include <pwd.h> struct passwd *getpwuid(uid_t uid);
			getgrgid(a.st_gid)->gr_name,\
			//#include <grp.h> struct group *getgrgid(gid_t gid);
			a.st_size,timecut,path
			);
}

int cmp(const void *left,const void *right)
{
	struct dirent* a=*((struct dirent**)left);
	struct dirent* b=*((struct dirent**)right);
	return strcmp(a->d_name,b->d_name);
}

void mode_to_str(mode_t md,char *buf)
{
	strcpy(buf,"----------\0");
	if(S_ISREG(md))//regular file
	{
		buf[0]='-';
	}else if(S_ISDIR(md))//directory file
	{
		buf[0]='d';
	}else if(S_ISCHR(md))//character special file
	{
		buf[0]='c';
	}else if(S_ISBLK(md))//clock special file
	{
		buf[0]='b';
	}else if (S_ISFIFO(md))//pipi or FIFO
	{
		buf[0]='p';
	}else if (S_ISLNK(md))//symbolic linl
	{
		buf[0]='l';
	}else if (S_ISSOCK(md))//socket
	{
		buf[0]='s';
	}
//now start the mask part
	if(md&S_IRUSR) buf[1]='r';
	if(md&S_IWUSR) buf[2]='w';
	if(md&S_IXUSR) buf[3]='x';
	
	if(md&S_IRGRP) buf[4]='r';
	if(md&S_IWGRP) buf[5]='w';
	if(md&S_IXGRP) buf[6]='x';

	if(md&S_IROTH) buf[7]='r';
	if(md&S_IWOTH) buf[8]='w';
	if(md&S_IXOTH) buf[9]='x';

	buf[10]=0;
}


