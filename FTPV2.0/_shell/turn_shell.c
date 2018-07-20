/*************************************************************************
> File Name: turn_shell.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年03月03日 星期二 12时33分31秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
    char *command[] = {"-a"};
    if(fork()==0){

        if(fork()==0)
        {
            printf("i'm here\n");
            execv("/bin/ls",command);
            printf("if print here, execv failed \n");
            exit(1);
        }else{
            printf("father waiting\n");
            wait(NULL);
        }
        printf("end of\n");
    }else{
        wait(NULL);
    }
}
