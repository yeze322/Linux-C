#include<stdio.h>
#define N 16
void ten_to_two(int each[],/*long long */int data)
{
	int i;
	if(data<0)
	{
		data=2147483648+data;
	}
	for(i=0;i<32;i++)
	{
		if(data==0)
			break;
		each[i]=data%N;
		data=data/N;
	}
	char two[32];int j;
	for(j=0,--i;i>=0;i--)
		two[j++]=(char)(each[i]<10?each[i]+'0':each[i]-10+'A');
	two[j]='\0';
	printf("%s\n",two);
	//左移按位取反，右移，+1
}
int main()
{
	int each[32]={0};
	/*long long */int data;//=999999999999;
	while(scanf("%lld",&data))
	{
		ten_to_two(each,data);
		//fflush(stdin);
	}
	"qweqwewq"[2];
	getchar();getchar();
}
