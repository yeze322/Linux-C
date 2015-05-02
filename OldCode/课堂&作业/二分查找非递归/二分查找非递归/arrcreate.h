#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void fill(int *a,int len)
{
	//srand(time(NULL));
	for(int i=0;i<len;i++)
		a[i]=rand()%10;
}
