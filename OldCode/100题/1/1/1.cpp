/*第1题 m个人的成绩存放在score数组中，请编写函数fun
它的功能是：将低于平均分的人数作为函数值返回，
将低于平均分的分数放在below所指定的函数中。*/
#include<iostream>
int fun(int score[],int m,int below[])
{
	float aver=0;
	for(int i=0;i<m;i++)
		aver=aver+score[i];
	aver=aver/m;//考虑恰好是一个整数？所以用float。参考隐式转换
	std::cout<<"aver="<<aver<<'\n';
	int j=0;
	for(int i=0;i<m;i++)
	{
		if(score[i]<aver)
			below[j++]=score[i];
	}
	return(j);
}

int main()
{
	int score[10]={1,2,3,4,5,6,7,8,9,10},m=9;
	int below[10]={0};
	int N=fun(score,m,below);
	std::cout<<"N="<<N<<'\n';
	int i=0;
	while(below[i])
	{
		std::cout<<below[i++]<<'-';
	}
	getchar();
	return 0;
}