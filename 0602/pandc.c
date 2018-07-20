/*************************************************************************
> File Name: productor_and_consimer.c
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月06日 星期五 21时00分54秒
************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#define LEN 128
#define QSIZE 20

/*typedef struct quereturn
{
char **que;
int que_capa;
int que_size;
int head,tail;
pthread_mutex_t lock;
pthread_cond_t m_pro,m_con;

    Q myque;
    memset(&myque,0,sizeof(Q));
    }Q;*/

pthread_mutex_t lock;

typedef struct taskpooldividebyprocess
{
    char ***task;
    int *task_index;

    int *task_finish;
    int thread_num;
}T;
T myt;

void T_init(T *tas,int i_thread_num,int qsize);
void T_destroy(T *tas,int i_thread_num);
void* whattodo(void *arg)
{
    int which = *(int*)arg;
    int i;
    printf("I'm active,%d \n",which);
    while(1){
        for(i=0;i<QSIZE;i++)
        {
            if((myt.task[which][i])!=NULL){
                printf("I'm %d,%d, %s\n",which,i,myt.task[which][i]);
                free(myt.task[which][i]);
                myt.task[which][i]=NULL;
                //I forget to set pointer to NULL, this made mistake,because when you visit it the next time ,it's a invalid value
            }
        }
    }
    printf("thread %d is end\n",which);
}
void* deliver(void *arg)
{
    int thread_num=*(int*)arg;
    int i;
    printf("d.0 %d\n",thread_num);
    while(1){
        for(i=0;i<thread_num;i++)
        {
            char *buf = (char *)calloc(128,sizeof(char));
            read(0,buf,127);
            printf("this task will be given to [%d]\n",i);
            int j;
            for(j=0;j<QSIZE;j++)
            {
                if(myt.task[i][j]==NULL)
                {
                    myt.task[i][j] = buf;
                    printf("push it in [%d] %s\n",j,myt.task[i][j]);
                    break;
                }

            }
        }
    }
}

int main(int argc,char *argv[])
{
    int i_thread_num = 3;//atoi(argv[1]);
    int i;
    printf("1\n");
    T_init(&myt,i_thread_num,QSIZE);
    printf("2\n");
    pthread_t *consumer = (pthread_t *)calloc(i_thread_num,sizeof(pthread_t));
    printf("3\n");
    //负载平衡，各进程工作量分配原则
    pthread_t collector;
    printf("4\n");
    pthread_create(&collector,NULL,deliver,(void *)&i_thread_num);
    for(i=0;i<i_thread_num;i++)
    {
        printf("5\n");
        pthread_create(consumer+i,NULL,whattodo,(void *)&i);
    }
    for(i=0;i<i_thread_num;i++)
    {
        pthread_join(*(consumer+i),NULL);
    }
    pthread_join(collector,NULL);
}

void T_init(T *tas,int i_thread_num,int qsize)
{
    tas->task = (char ***)calloc(i_thread_num,sizeof(char **));
    int i;
    for(i=0;i<i_thread_num;i++)
    {
        tas->task[i] = (char **)calloc(qsize,sizeof(char *));
    }//task[prossess 1][i] is a str's head address
    tas->task_index = (int *)calloc(i_thread_num,sizeof(int));
    tas->task_finish = (int *)calloc(i_thread_num,sizeof(int));
    tas->thread_num = i_thread_num;
}
void T_destroy(T *tas,int i_thread_num)
{
    int i;
    for(i=0;i<i_thread_num;i++)
    free(tas->task[i]);
    free(tas->task);
    free(tas->task_index);
    free(tas->task_finish);

}
