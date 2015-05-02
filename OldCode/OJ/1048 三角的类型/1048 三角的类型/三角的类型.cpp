#include<assert.h>
#include<stdio.h>
void swap(int &a,int &b){if(a>b){int temp=a;a=b;b=temp;}}

int main()
{
	int side[3]={0};
	while(scanf("%d%d%d",&side[0],&side[1],&side[2])==3)
	{
		swap(side[0],side[1]);
		swap(side[1],side[2]);
		swap(side[0],side[1]);
		//冒泡,从小到大
		if(side[0]+side[1]<=side[2])
			continue;
		int add=side[0]*side[0]+side[1]*side[1];
		int big=side[2]*side[2];
		if(add>big)
			printf("锐角三角形\n");
		else if(add==big)
			printf("直角三角形\n");
		else
			printf("钝角三角形\n");
	}
}
