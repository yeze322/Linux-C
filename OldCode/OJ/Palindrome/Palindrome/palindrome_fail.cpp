#include<iostream>
#include<string.h>
using namespace std;
const int N=500;
char s[N];
void tst(char a)
{
	cout<<a<<';';
}
void ifpalin()//我觉得我应该用预处理。。。。。。！！！！！！已然不想写了,数据结构的重要性！
{
	int left,right,i=1;
	while(s[i])
	{
		//tst('A');
		//寻找第一个非符号点。
		while(!isalpha(s[i]))
		{
			i++;
			//tst('B');
		}
		left=i-1;right=i+1;
		while(left>=0&&!isalpha(s[left]))
		{
			left--;
			//tst('C');
		}//寻找标点左边第一个非符号点。
		while(s[right]&&!isalpha(s[right]))
		{
			right++;
			//tst('D');
		}//寻找右边第一个非符号点。

		if(isalpha(s[right])&&isalpha(s[left]))//必须是左右都有才能判断。
		{		
			while(s[left]==s[right]&&left>=0&&s[right])
			{
				//tst('E');
				while(left>=0&&!isalpha(s[left]))//不出界而且不是字母
					left--;
				while(s[right]&&!isalpha(s[right]))
					right++;//写在while里可以多加一次
			}
			if(left!=(i-1)&&left!=right)
			{
				for(int j=left;j<=right;j++)
					cout<<s[j];
				cout<<'\n';
			}
		}
		i++;
		//两种情况。用两次。不能用if简化，没想好一串aaaaaaaaaaa时怎么处理
	}
}

int main()
{
	FILE *fin;
	fin=fopen("input.txt","rb");
	s[N]=fscanf(fin,"%s",s);
	ifpalin();
	getchar();
}