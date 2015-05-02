#include<iostream>
#include<cstring>
using namespace std;
const int N=10;
int wall[N]={2,5,1,2,3,4,7,7,6};
//如果想要存住水，则需要一个墙不低于左右墙的值。
//因此首先find_peak来寻找峰值，peak[]中存储的是wall的角标。
void find_peak(int wall[],int peak[])
{
	int count=0;
	if(wall[0]>wall[1])	peak[count++]=0;
	for(int i=1;i<N-1;i++)
	{
		if(wall[i-1]<=wall[i]&&wall[i+1]<=wall[i])
			peak[count++]=i;
	}
	if(wall[N-1]>wall[N-2])	peak[count++]=N-1;

}
//接下来计算水容量。仅在两个峰之间才会出现水。
int calcu_water(int left,int right)
{
	int volumn=0;
	int board=(wall[left]<=wall[right])?wall[left]:wall[right];
	//两个峰，水位最高为较低的峰值，定义为board
	for(int i=left;i<=right;i++)
	{
		if(wall[i]<=board)
			volumn+=(board-wall[i]);
		//高于board的墙不会存水，不计算。
	}
	return volumn;
}
int water(int *a)
{
	int peak[N],i=0,volumn=0;
	memset(peak,-1,sizeof(peak));

	find_peak(wall,peak);
	while (peak[i+1]>=0)
	{
		volumn+=calcu_water(peak[i],peak[i+1]);
		i++;
	}
	return volumn;
}
int main()
{
	cout<<water(wall);
	getchar();
}