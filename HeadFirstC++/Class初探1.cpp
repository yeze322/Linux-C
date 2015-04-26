#include<iostream>
using namespace std;
//类声明段
class Time
{
public:
	void settime(int = 11, int = 20, int = 30);
	void showtime(void);
private:
	int hour,min,sec;
};
//类实现段
void Time::settime(int hour, int min, int sec)
//范围解析运算符：编译器区别哪个hour是类数据成员，哪个是函数传入的值
{
	Time::hour=hour;
	Time::min=min;
	Time::sec=sec;

}

void Time::showtime()
{
	cout<<hour<<':'<<min<<":"<<sec<<endl;
	return;
}
//****//
int main()
{
	Time arrival,departure,clock[10];
	Time *p=&arrival;//Time *p;p=&arrival;

	arrival.settime();
	departure.settime(14,30,55);

	cout<<"Arrival time:";
	arrival.showtime();
	cout<<"Arrival time(*p):";
	p->settime(8,58,34);
	p->showtime();
	(*p).showtime();
	cout<<"Departure time:";
	departure.showtime();

	for(int i=0;i<3;i++){
		clock[i].settime();
		cout<<"clock["<<i<<"] is:";
		(clock+i)->showtime();/*这个式子很有意思！C++中数组名=数组地址*/
	}
	getchar();
	return 0;
}
/*堆栈(struct用)的执行效率要比堆（class用）的执行效率高，可是堆栈的资源有限，不适合处理大的逻辑复杂的对象。
所以结构处理作为基类型对待的小对象，而类处理某个商业逻辑
因为结构是值类型所以结构之间的赋值可以创建新的结构，而类是引用类型，类之间的赋值只是复制引用*/