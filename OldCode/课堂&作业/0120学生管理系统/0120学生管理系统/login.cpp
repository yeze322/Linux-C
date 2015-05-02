//登录选项。用于选择su还是guest
#include"_SIMS.h"
void login()//StuInfo *L)
{
	system("cls");
	char name[NAMELEN]="su";
	cout<<"User ID:";
	cin>>name;
	char password[PSWDLEN]="";
	if(strcmp(name,"su")==0)
	{
		cout<<"input password:";
		char ps;int i=0;
		while((ps=getch())!=EOF)
		{
			if(ps=='+')
				break;
			putchar('*');
			password[i++]=ps;
		}//为了方便默认su先
		putchar('\n');
		if(strcmp(password,"yeze")==0)
			SU_BLOCK();
		else
			return;
	}
	else if(strcmp(name,"g")==0)
	{
		cout<<"input password:";
		char ps;int i=0;
		while((ps=getch())!='+')
		{
			putchar('*');
			password[i++]=ps;
		}
		putchar('\n');
		if(strcmp(password,"123")==0)
			GUS_BLOCK();
		else
			return;
	}
	//else if(strcmp(name,"exit")==0)
		return;

}
