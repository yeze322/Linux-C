#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
	int N;
	while(cin>>N)
	{
		if(N<=0)
			continue;
		int max,min,temp;
		cin>>temp;max=min=temp;
		for(int i=1;i<N;i++)
		{
			cin>>temp;
			if(temp>max)
				max=temp;
			else if(temp<min)
				min=temp;
		}
		cout<<max<<" "<<min<<endl;
	}
}
