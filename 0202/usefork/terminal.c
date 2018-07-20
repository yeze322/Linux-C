/*************************************************************************
	> File Name: tereminal.c
	> Author: YeZe
	> Mail:a@b.com 
	> Created Time: Mon 02 Feb 2015 15:07:14 UTC
 ************************************************************************/
#include "chat.h"

int main(int argc, char *argv[])
{
	int fdread=open(argv[1],O_RDWR);
	int fdwrite=open(argv[2],O_RDWR);
	pid_t pid=fork();
	switch(pid){
		case -1:
			printf("for failed\n");
			exit(1);
		case 0:
			child(fdread);
			exit(0);
		default:	
			parent(fdwrite);
			exit(0);
	}
	printf("done [%d]\n",getpid());
	exit(0);
}
