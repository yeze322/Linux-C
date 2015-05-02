#include<iostream>
#include<time.h>
#include "student.h"
using namespace std;
#define N 25
int main()
{
	srand(time(NULL));

	//STU class21[N];
	STU *class21=new STU[N];
	for(int i=0;i<N;i++)
		givevalue(class21[i],i);
	qsort(class21,N,sizeof(STU),&STUcmp);
	printitem(class21,N);
	return 0;
}
