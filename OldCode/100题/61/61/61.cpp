/*第61题 第请编写函数fun，该函数的功能使：
统计各年龄段的人数。N个年龄通过调用随机函数获得，并放在主函数的age数组中；
要求函数把0至9岁年龄段的人数放在d[0]中，
把10至19岁年龄段的人数放在d[1]中
，把20至29岁的人数放在d[2]中，其余以此类推，
把100岁(含100以上年龄的人数都放在d[10]中。结果在主函数中输出。*/
#include<iostream>
const int N=10;
void fun(int age[],int d[])
{
	for(int i=0;i<N;i++)
	{
		if(1)
			;
		else if(1)
			;
		else if(1)
			;
		else if(1)
			;
		else
			;
	}
}

int main()
{
	int age[N];
	for(int i=0;i<N;i++)
		age[i]=rand()%100;
	//int d[10];
	//fun(age,d);
	//for(int i=0;i<10;i++)
	//	std::cout<<d[i]<<"--";
	std::cout<<age[N];
	getchar();
}