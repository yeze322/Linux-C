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
		case '5':SU_FUN5();break;
		case '6':SU_FUN6();break;
		case '7':SU_FUN7();break;
		case '8':SU_FUN8();break;
		case '0':return;
		}
	}
}

void SU_PRINT()
{
	cout<<"SU_PRIT\n";
	cout<<"		1-查询\n"
		<<"		2-添加\n"
		<<"		3-更新\n"
		<<"		4-删除\n"
		<<"		5-fun5\n"
		<<"		6-fun6\n"
		<<"		7-fun7\n"
		<<"		8-fun8\n"
		<<"		0-退出\n";
	cout<<"选择一个功能！";
}


void SU_FUN1()
{
	cout<<"SU+FUN  1"<<endl;
}

void SU_FUN2()
{
	cout<<"SU+FUN  2\n"<<endl;
}

void SU_FUN3()
{
	cout<<"SU+FUN	3\n"<<endl;
}

void SU_FUN4()
{
	cout<<"SU+FUN	4\n"<<endl;
}

/*void SU_FUN4()
{
	cout<<"SU+FUN4"<<endl;
}*/

void SU_FUN5()
{
	cout<<"SU+FUN 5\n"<<endl;
}
void SU_FUN6()
{
	cout<<"SU+FUN	6\n"<<endl;
}
void SU_FUN7()
{
	cout<<"SU+FUN	7\n"<<endl;
}
void SU_FUN8()
{
	cout<<"SU+FUN	8\n"<<endl;
}