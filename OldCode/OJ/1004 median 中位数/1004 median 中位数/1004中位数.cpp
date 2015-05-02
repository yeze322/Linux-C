/* Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the non-decreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
    Given two increasing sequences of integers, you are asked to find their median.*/
#include<stdio.h>
int main()
{
	long int num1,num2;char ch;
	while(scanf("%ld",&num1)!=EOF)
	{
		for(int i=0;i<(num1-1)/2;i++)//N¸öÊý£¬ÀýÈçN=100,0-48³Ôµô,49-¡·48£»101,51-¡·50,0--49³Ôµô
			scanf("%ld",&num2);
		long int mid1;scanf("%d",&mid1);
		while((ch=getchar())!='\n');

		scanf("%ld",&num2);
		for(int i=0;i<(num2-1)/2;i++)
			scanf("%ld",&num1);
		long int mid2;scanf("%ld",&mid2);
		while((ch=getchar())!='\n'&&ch!=EOF);
		
		printf("%ld\n",(mid1+mid2)/2);
	}
	return 0;
}	