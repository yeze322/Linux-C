/*************************************************************************
> File Name: ssh_scan.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年03月11日 星期三 00时16分24秒
************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
void num_to_str(int i,char *a){
    char temp[4]="";
    char *p = temp;
    while(i!=0)
    {
        *p++ = '0'+(i%10);    
        i=i/10;
    }
    int len = strlen(temp);
    for(i=len-1;i>=0;i--)
    a[i] = temp[len-1-i];
}
int main(int argc,char *argv[])
{
    int i=2;
    char str[4]="";
    for(i;i<255;i++)
    {
        if(fork()==0){
            num_to_str(i,str);
            // printf("%s:",str);
            char *argv[] = {"1",str,NULL};
            int pid = getpid();
            // printf("%d\n",pid);
            if(fork()==0){
                sleep(5);
                //    printf("kill %d ",i);
                kill(pid,9);
                exit(1);
            }
            if(execv("./_ssh.sh",argv)==-1)
            perror("shell failed\n");
            wait(NULL);
            exit(0);
        }
    }   
    sleep(8);//why I must add sleep here? you still don't understand how fork exit
}
