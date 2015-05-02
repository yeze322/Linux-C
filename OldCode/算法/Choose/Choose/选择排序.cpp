#include<stdlib.h>
int main()
{
	int a[10]={10,9,1,4,82,2,3,4,83,62};
	int max=0x80000000,big=0x80000000;
	for(int i=1;i<10;i++)
	{
		if(a[i]>max)
		{
			big=max;
			max=a[i];			
		}
		
	}
	return 0;
}