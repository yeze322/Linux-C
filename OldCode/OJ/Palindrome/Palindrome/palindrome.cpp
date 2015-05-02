/*

#include<iostream>
#include<string.h>
using namespace std;
const int N=500;
char s[N];
void tst(char a)
{
	cout<<a<<';';
}
void printpalin()
{
	//预处理，过滤掉非字符。
	char* pre[N];
	int pre_i=0;

	for(int j=0;j<sizeof(s)-1;j++)
	{
		if(isalpha(s[j]))
		{
			pre[pre_i++]=&s[j];//存放原来的地址
		}
	}
	//预处理完毕。通过指针操作s中数字。
	int left,right,i=1;//边界溢出了！！经过无数次的调试：原因竟然是sizeof（pre）=2000，这是我没有想到的。因为这个错误，耽误了好长好长时间！
	while(i<pre_i)
	{	
		int move=0;
		left=i-1;right=i+1;
		while(left>=0&&right<pre_i&&(*pre[left]==*pre[right]||(*pre[left]==*pre[right]+'a'-'A')||(*pre[left]==*pre[right]+'A'-'a')))
		{
			left--;
			right++;
			move++;
		}
		if(move)
		{
			right--;
			for(char* j=pre[++left];j<=pre[right];j++)//末端处理不好，总是会多输出和下一个字母间的符号。
				//原来是因为把'--'写在了for循环里，造成了被执行多次！！！这点要注意！这个程序里各种BUG，都是意外的。
				//其实也很简单，边界条件考虑还是不周全！对sizeof还是不熟练。
				cout<<*j;
			cout<<'\n';
		}
		//另一种情况，对称字符串。
		move=0;
		left=i-1;right=i;
		while(left>=0&&right<pre_i&&(*pre[left]==*pre[right]||(*pre[left]==*pre[right]+'a'-'A')||(*pre[left]==*pre[right]+'A'-'a')))
		{
			left--;
			right++;
			move++;
		}
		if(move)
		{
			right--;
			for(char* j=pre[++left];j<=pre[right];j++)
				cout<<*j;
			cout<<'\n';
		}
		i++;
	}
}

int main()
{
	FILE *fin;
	fin=fopen("input.txt","rb");
	s[N]=fscanf(fin,"%s",s);
	printpalin();
	getchar();
}

*/