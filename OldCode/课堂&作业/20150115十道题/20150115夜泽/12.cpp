//求一个二维整数数组的最大值和最小值。 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 8
#define M 10
int cmpint(const void *left,const void *right)
{
	int *a=(int *)left;
	int *b=(int *)right;
	if(*a<*b)
		return 1;
	else
		return (*a==*b?0:-1);
}

int main()
{
	int a[N][M];
	srand(time(NULL));
	//____________create___________
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			a[i][j]=rand()%999;
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	qsort(a,M*N,sizeof(int),cmpint);
	printf("\nMAX:  %d\n",a[0][0]);
	printf("MIN:  %d",a[N-1][M-1]);
	return 0;

}
