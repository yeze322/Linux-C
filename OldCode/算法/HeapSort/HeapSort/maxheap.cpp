#include<stdio.h>
#include "heap.h"
int main()
{
	int a[16]={1,2,3,4,5,6,7,8,9};
	CreateHeap(a);
	heaptravel(head);
	displayheap1(head);
	printf("\n");
	displayheap2(head);
	getchar();
}