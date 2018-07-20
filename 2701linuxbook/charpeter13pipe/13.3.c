/*************************************************************************
	> File Name: 13.2.c
	> Author:YeZe 
	> Mail:a@b.com 
	> Created Time: Tue 27 Jan 2015 13:44:10 UTC
 ************************************************************************/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *write_fp;
	char buffer[BUFSIZ+1];
	
	sprintf(buffer,"Once upon a time, ther was ...\n");
	write_fp = popen("od -c", "w");

	if(write_fp!=NULL){
		fwrite(buffer,sizeof(char),strlen(buffer),write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);


}
