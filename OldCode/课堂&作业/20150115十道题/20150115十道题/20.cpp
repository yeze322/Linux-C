#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
double ratio(double profit,int T)
{
	double rat=1+profit*12*T;
	int calc=20/T;
	double ratperyear=pow(rat,1.0/T);
	return ratperyear;//pow(rat,calc);
}
int doublecmp(const void *left,const void * right)
{
	double *a=(double *) left;
	double *b=(double *) right;
	if(*a<*b)
		return 1;
	else return *a==*b?0:-1;
}

int main()
{
	double profit[5]={0.0063,0.0066,0.0069,0.0075,0.0084};
	int T[5]={1,2,3,5,8};
	double after20years[5];
	for(int i=0;i<5;i++)
	{
		after20years[i]=ratio(profit[i],T[i]);
		printf("第%d种选择的获利倍数为： %.4f\n",i+1,after20years[i]);
	}
	qsort(after20years,5,sizeof(double),doublecmp);
	printf("收益最高的利润为：%.2f\n",after20years[0]*2000-2000);
	return 0;
}
