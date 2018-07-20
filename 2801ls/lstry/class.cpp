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
int main(int argc ,char *argv())
{
	char *p="hellaosoddas\n";
	int fd= open(argc[1],O_WRONLY | O_CREAT,0666);
	dup2(1,fd);
	//int fd= dup(1);
	//	int fd=1;
	close(1);
	write(fd,p,strlen(p));
	return 0;
}

