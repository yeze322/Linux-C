#include<stdio.h>
#define N 9
int main()
{
	int a[N][N];
	printf("/*************TITLE****************/\n  ");
	for(int i=0;i<N;i++)
		printf("%4d",i+1);
	printf("\n");
	for(int i=1;i<=N;i++){
		printf("%2d",i);
		for(int j=1;j<=N;j++){
			printf("%4d",i*j);
		}
		printf("\n");
	}
	return 0;
}
