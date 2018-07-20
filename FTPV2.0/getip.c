/*************************************************************************
	> File Name: getip.c
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年03月02日 星期一 15时18分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
    char buf[100]="";
    read(0,buf,100);
    char *ip = strstr(buf,"192.168.1.");
    char *temp = ip;
    while((*temp)!=' '){
        temp++;    
    }
    *temp = '\0';
    printf("%s",ip);
}
