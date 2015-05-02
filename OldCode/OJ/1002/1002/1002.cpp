#include<stdio.h>
#include<stdlib.h>
int main()
{
	int P,T,G1,G2,G3,GJ;
	while(scanf("%d %d %d %d %d %d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF)
	{
		double grade;
		if(abs(G1-G2)<=T)
			grade=(G1+G2)*1.0/2.0;
		else if(abs(G1-G2)>T)
		{
			if(abs(G1-G3)<=T&&abs(G3-G2)>T)
				grade=(G1+G3)*1.0/2.0;
			else if(abs(G3-G2)<=T&&abs(G1-G3)>T)
				grade=(G2+G3)*1.0/2.0;
			else if(abs(G3-G2)<=T&&abs(G1-G3)<=T)
				grade=(G1+G2+G3)*1.0/3.0;
			else if(abs(G1-G2)>T&&abs(G1-G3)>T)
				grade=GJ*1.0;
		}
		printf("%.1f\n",grade);
	}
	return 0;
}
//bool within(int G1,int G2,int T)
//{
//	if(G1-G2<=T&&G1-G2>=T*-1)
//		return true;
//	return false;
//}