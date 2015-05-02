#include "_SIMS.h"
//guest账户，仅包括查询权限
extern StuInfo *L;


void GUS_BLOCK()//StuInfo *L)
{
	system("cls");
	char c;
	while(fflush(stdin),system("cls"),GUS_PRINT(),(c=getchar())!=EOF)
	{
		fflush(stdin);
		switch (c)
		{
		default:break;
		case '1':SearchSTU();break;
		case '0':return;
		}
	}
}

void GUS_PRINT()
{
	cout<<"________GUS\n1-Search\n";
	cout<<"\n0-exit\n";
}
