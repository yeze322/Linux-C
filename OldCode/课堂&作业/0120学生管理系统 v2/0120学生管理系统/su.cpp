//su账户，包括增删改查权限
#include "_SIMS.h"

void SU_BLOCK()//StuInfo *L)
{
	system("cls");
	char ch;
	
	while(fflush(stdin),system("cls"),SU_PRINT(),(ch=getchar())!=EOF)
	{
		fflush(stdin);
		switch (ch)
		{
		default:
			break;
		case '1':SearchSTU();break;
		case '2':AddSTU();break;
		case '3':UpdateSTU();break;
		case '4':DelSTU();break;
		case '5':ChaxunUSR();break;
		case '6':AddUSR(); break;
		case '7':UpdateUSR();break;
		case '8':DelUSR();break;
		case '0':return;
		}
	}
}

void SU_PRINT()
{
	cout<<"\n\n\n\n		==========管理员模式=========\n\n";
	cout<<"			1-查询学生信息\n"
		<<"			2-添加学生信息\n"
		<<"			3-更新学生信息\n"
		<<"			4-删除学生信息\n"
		<<"			---------------\n"
		<<"			5-查询账户信息\n"
		<<"			6-添加新的账户\n"
		<<"			7-更改账户信息\n"
		<<"			8-删除账户信息\n\n"
		<<"			0-  退出输入0\n";
	cout<<"		===========>>>>>>>>>==========\n\n";
	cout<<"选择一个功能---->>>>>>";
}