#include<iostream>
using std::cout;
class A {
private:
	int x;
	int y;
	int z;
public:
	A(): x(0),y(0),z(0){};
	A(int val): x(val){};
	virtual void printA() {cout<<"x = "<<x<<",y = "<<y<<",z = "<<z<<std::endl;}
};
using std::cout;
class book {
public:
	int a;
	int b;

	book(): a(9),b(-1){}
	virtual void print33(){cout<<(a*10)<<std::endl;}
	void print1(){cout<<"asd"<<std::endl;}
	void print12(){cout<<a+1<<std::endl;}

};

class novel : public book {
public:
	int num;
	int a;
	void print(){cout<<"heheda\n"<<std::endl;}
	virtual void print123(){cout<<"heheda\n"<<std::endl;}
	novel(): num(11){}
};

int main()
{
	book history;
	novel GoneWith;
	(dynamic_cast<book*> (&GoneWith))->print12();
	/*GoneWith因为cast而收缩了自己的范围，因此GoneWith的print成员不能用*/
	//int cd = (dynamic_cast<novel*> (&history))->num;
	/*卧槽这cd怎么能用？只是扩大指针的范围，你后面那片还是没数据啊*/
	/*看来没有调动构造函数，只是读取了一片未定义内存*/
	/*果断这个是不安全的！有时会报错*/
	//(dynamic_cast<novel*> (&history))->print12();/*history拓展为一个novel*/
	//history转化为novel，那么它就能去寻找novel下的函数.说明这些函数是单独放出来的。
	/*print33没有问题，动态绑定的。而print：history 并没有合适的空间来存放print函数，说明这个print不以函数表的形式存在，而是静态*/
	/*这里报错了，访问冲突。问题出在变量a的访问有问题*/
	/*只是编译器认为它的边界拓展，等访问的时候就会访问一个把原来的a覆盖的、内存中不存在的a*/
	/*可见，强制转换带来的不安全性。尤其是负责较小空间的指针转换成负责较大空间的指针时*/
	
	/*问题二，各种cast的结果不同*/
	(dynamic_cast<novel*> (&history))->print12();/*history拓展为一个novel，报错*/
	(reinterpret_cast<novel*> (&history))->print12();/*history拓展为一个novel，可运行输出10*/
	(static_cast<novel*> (&history))->print12();/*history拓展为一个novel，输出10 ---》说明访问的是book::a而不是novel::a */

	return 0;
}

/* 
conslusion:
class won't call it's constructor twice.
*/