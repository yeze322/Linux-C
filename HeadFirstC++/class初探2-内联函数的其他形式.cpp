#include<iostream>
using namespace std;
class Time
{
	int hour,min,sec;
	//其实默认访问为private。可以直接写在前面！
	//默认使 [数据成员] 和 [public关键字]上面的成员函数 成为private
public:	
	void settime(int a, int b, int c)
	{//完全在类定义中定义的函数自动生成为内联函数，不需要声明
	//但是这种方法往往使得类定义很混乱不易于读懂类的结构。所以我们还是选用inline来生成内联函数
		hour=a;
		min=b;
		sec=c;
		return;
	}
	inline void showtime(void);//这种方法比较好！
//private:
//	int hour,min,sec;
};

inline void Time::showtime()
	{
		cout<<hour<<':'<<min<<":"<<sec<<endl;
		return;
	}
//书中说：“通常，类中的数据是专用的，而函数是公开的。
//隐藏数据-》为了防止误操作。公开函数-》便于类外访问”
//但是要知道，public数据/pricate函数也是可用的！
//****//
void main()
{}