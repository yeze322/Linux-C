#include<iostream>
#include<vector>
using  std::vector;
using std::cout;
class A {
private:
	int x;
	int y;
	vector<int> vec1;
public:
	A(): x(0),y(0){};
	A(int val): x(val){};
};

int main()
{
	A a(1);
	return 0;
}

/* 
conslusion:
class won't call it's constructor twice.
*/