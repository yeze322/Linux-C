#include "BOOK.h"
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	book A,*p_to_A;
	p_to_A=&A;
	A.initbook();
	A.showbook();
	cout<<"\n*Use *p_to_A\n\n";
	(*p_to_A).showbook();
	getchar();getchar();getchar();
	return 0;
}