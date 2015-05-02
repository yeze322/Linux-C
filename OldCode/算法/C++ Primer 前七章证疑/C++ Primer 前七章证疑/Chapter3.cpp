#include<deque>
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<set>

//#include<>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::aligned_storage;
using std::list;
using std::deque;
using namespace std;
void fun(const char s[]){}
int main()
{
	vector<int> vec(10);
	string str = "hello";
	fun(str.c_str);
	vector<int> s(10);
	int a[10] = {0};
	for(int i=0;i<20;i++)
	{
		s.insert(s.end(),a,a+10);
		
	}
	return 0;
}