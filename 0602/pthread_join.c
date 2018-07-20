/*************************************************************************
	> File Name: pthread_join.c
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年02月06日 星期五 10时01分41秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
void *ThreadFunc(void *pArg)
{
    int iArg = (int)pArg; //将 void*转换为 int
    sleep(iArg);
    if(iArg < 3)
    return (void *)(iArg*2);
    else
    pthread_exit((void *)(iArg*2)); //和 return 达到的效果一样,都可以用于正常返回

}
int main()
{
    pthread_t thdId;
    int iRet = 0;
    pthread_create(&thdId, NULL, ThreadFunc, (void *)2 ); //传递参数值为 2
    pthread_join(thdId,(void **)&iRet); //接收子线程的返回值
    printf("The first child thread ret is:%d\n",iRet);
    pthread_create(&thdId, NULL, ThreadFunc, (void *)4 );
    pthread_join(thdId,(void **)&iRet);
    printf("The second child thread ret is:%d\n",iRet);
    return 0;

}
