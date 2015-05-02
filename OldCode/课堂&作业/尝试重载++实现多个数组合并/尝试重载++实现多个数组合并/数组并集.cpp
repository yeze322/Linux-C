#include<iostream>
using namespace std;
class arr_tree
{
public:
	int *arr;
	int length;
	arr_tree* father;
	arr_tree* son;
	//arr_tree& operator++(const arr_tree&);
};
//arr_tree& operator++(const arr_tree &a);
ostream& operator<<(ostream &os,const arr_tree &a)
{
	for(int i=0;i<a.length;i++)
		os<<a.arr[i]<<" ";
	return os;
}

int main()
{
	int a[5]={1,2,3,4,5};
	int *p=a;
	p++;p++;
	printf("%d",p-a);
	return 0;
}