#include<string>
#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
const int maxn = 1000;
class BigNumCal
{
private:
	struct bign
	{
		int num[maxn];
		int len;
		bign(){memset(num,0,sizeof(num)),len=1;}
		~bign(){(num,0,sizeof(num)),len=1;}
		bign operator = (const char *s)
			//reload the operator =
		{
			len=strlen(s);
			for(int i=0;i<strlen(s);i++)//the writer want to reverse it!
				num[i]=s[strlen(s)-i-1]-'0';
			return *this;//?
		}
		bign operator = (int a)
		{//reload str to char
			char str[maxn];
			sprintf(str,"%d",num);
			*this =str;
			return *this;//?
		}
		//in order to support initialize
		bign operator = (int a){*this = num;}
		bign operator = (const char * num){*this = num;}
		string str() const
		{
			string res = "";
			for(int i=0;i<len;i++)
				res=char(num[i]+'0') + res;
			return res;
		}
	};
	ostream& operator << (const bign &x)
	{
		cout<<x.str();
		return cout;
	}
	istream& operator >> (bign &x)
	{
		string s;
		cin>>s;
		x=s.c_str();
		return cin;
	}

};


int main()
{

}
