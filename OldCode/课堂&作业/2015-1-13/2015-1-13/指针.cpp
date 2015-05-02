#include<stdlib.h>
#include<iostream>
using namespace std;
struct bs
{
	int a:5;
	int b:3;
};
char swap(int& a,int& b)
{
	int temp=a;
	a=b;b=temp;
	return '0';
}

void fun1_1(int a[16][20])
{
	printf("%d___",sizeof(a));
	cout<<sizeof(*a)<<endl;
}

void fun1_2(char a[16][20])
{
	printf("%d---",sizeof(a));
	cout<<sizeof(*a)<<endl;
}

void fun2_1(int **a)
{
	printf("%d___",sizeof(a));
	cout<<sizeof(*a)<<endl;
}

void fun2_2(char **a)
{
	printf("%d___",sizeof(a));
	cout<<sizeof(*a)<<endl;
}
void somethingaboutpointer()
{
	/*int a[3][3];
	int count=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[i][j]=i*3+j;
	int (*p)[3]=a;

	int x=1,y=2;
	char (*fun_p)(int&,int&);
	fun_p=swap;
	fun_p(x,y);
	int size=sizeof(fun_p);*/
}

void something()
{
	int ch1_1[16][20];
	fun1_1(ch1_1);
	char ch1_2[16][20];
	fun1_2(ch1_2);
	
	int **ch2_1=new int* [16];
	fun2_1(ch2_1);
	char **ch2_2=new char* [16];
	fun2_2(ch2_2);

	int arr[][3]={
		1,2,3,
		4,5,6,
		7,8,9
	};
	int *p1=(int *)arr;
	cout<<*(p1+7);//二维数组是连续的特性
	int (*p2)[3]=arr;

	arr[2][1];

	bool ttt=(*(p1+2*3+1)==*(*(p2+2)+1));
	*((int *)(&arr+1)-1);//arr+1到下一个3*3矩阵，然后-1就是末尾元素
	(arr+1)[2];
	*(arr+1)[1];//7
	*(arr+1)+1;//&5
}

int main()
{
	char a[]="23e12e";
	char *p=a;
	char** ptr=&p;
	return 0;
}
