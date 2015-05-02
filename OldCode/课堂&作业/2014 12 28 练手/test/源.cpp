#include<cstdio>//C++使用C中头文件则这么写
#include<iostream>
using namespace std;

/*

void fun_bignumber()
{
	double a,b;
	a=111111*111111;
	b=(double)111111*(double)111111;
	printf("%f\n%f",a,b);
}
void fun_bignumber2()
{
	long int a,b,c;
	a=11111*11111;
	b=11111111111*11111111111;
	printf("%d\n%d",a,b);
}
void fun_int_max_min()//int 的上下界
{
	int a=1;
	int count=0;
	while((a*2)>0)
	{
		a=a*2;
		count++;
	}
	while(a>0)
	{
		a++;
	}
	printf("%d\n%d\n",a,count);//-2147483648
	printf("max=%d\nmin=%d\n",a-1,a);
}
void fun_double_maxmin()
{
	double a=8.0;
	int count=4;
	while((a-int(a/10)*10)>0&&((double)a*2/2==a))
	{
		a=(double)a*2;
		count++;
	}
	while(a>0)
	{
		a++;
	}
	printf("%f\n%d\n",a,count);//-2147483648
	printf("max=%f\nmin=%f\n",a-1,a);
}
void fun_file_re()//输入输出重定向。
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
void fun_file2()
{
	FILE *fin, *fout;
	fin=fopen("input.txt","rb");
	fout=fopen("output.txt","wb");

	int min=9999,max=-9999,x;
	
	while(fscanf(fin,"%d",&x)==1)
	{
		if(x<min) min=x;
		if(x>max) max=x;
	}

	fprintf(fout,"min=%d\r\nmax=%d",min,max);
	fclose(fin);
	fclose(fout);
}
void fun_float_trap()//浮点数陷阱。
{
	double i;
	for(i=0;i!=10;i+=0.1)
		printf("%.11f\n",i);
}
void fun_snake()
{
	const int n=3;
	int a[n][n]={0};
	int i=1;
	//fill the around area first.
	int k,l;int m=n;
	for(int m=n;m>0;m--)//方阵逐渐减小,for的边界会增加工作量，可以用while
	{
		for(k=n-m;k<m;k++)		a[k][m-1]=i++;
		k--;
		for(l=m-2;l>=n-m;l--)	a[k][l]=i++;
		l++;
		//for(int t=0;t<n;t++){for(int j=0;j<n;j++){cout<<a[t][j]<<" ";}cout<<'\n';}

		for(k--;k>=n-m;k--)		a[k][l]=i++;
		k++;
		for(l++;l<m-1;l++)		a[k][l]=i++;
		l--;
	}

	for(int t=0;t<n;t++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d  ",a[t][j]);
		}
	cout<<'\n';
	}
}
void fun_snake_for_v2()
{//缺点：对于奇数n时，中心处不会被赋值。
	const int n=5;
	int a[n][n]={0};
	int i=1;
	//fill the around area first.
	int k,l;
	for(int m=n;m>0;m--)//方阵逐渐减小,for的边界会增加工作量，可以用while
	{
		for(k=n-m;k<m-1;k++)	a[k][m-1]=i++;
		for(l=m-1;l>n-m;l--)	a[k][l]=i++;
		for(;k>n-m;k--)			a[k][l]=i++;
		for(;l<m-1;l++)			a[k][l]=i++;
		if(k==l) a[k][l]=i;
	}

	for(int t=0;t<n;t++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d  ",a[t][j]);
		}
	cout<<'\n';
	}
}
void fun_snake_while()
{
	const int n=5;
	int a[n][n]={0};
	int count=1;
	int i=0,j=n-1;
	a[i][j]=1;
	while(count<n*n)
	{
		while(!a[i+1][j]&&i<n-1)	a[++i][j]=++count;
		while(!a[i][j-1]&&j>0)		a[i][--j]=++count;
		while(!a[i-1][j]&&i>0)		a[--i][j]=++count;
		while(!a[i][j+1]&&j<n-1)	a[i][++j]=++count;
	}

	for(int t=0;t<n;t++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d  ",a[t][j]);
		}
	cout<<'\n';
	}
}

*/

int main()
{
	int a[10]={0};
	int *p=a;
	free(p);
	getchar();
	return 0;
}