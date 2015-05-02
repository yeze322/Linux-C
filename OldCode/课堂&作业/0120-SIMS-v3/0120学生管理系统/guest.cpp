#include "_SIMS.h"
//guest账户，仅包括查询权限
extern StuInfo *L;


USR* CreateUSR()
{
	USR *p1=new USR;
	p1->next=NULL;
	p1->permission=0;
	return p1;
}


USRINFO* CreateUSRINFO()
{
	USRINFO *p2=new USRINFO;
	p2->head=CreateUSR();
	p2->tail=p2->tail;
	p2->num_all=p2->num_su=0;
	return p2;
}


USRINFO* FileToUSR()
{
	FILE *fp=fopen(UsrSrc,"r");
	USRINFO *all=CreateUSRINFO();
	USR *visit=all->head;
	USR *p=CreateUSR();
	while(fscanf(fp,"%d%s%s",&p->permission,p->userid,p->password)==3)
	{
		USR *add=CreateUSR();
		visit->next=add;//point to
		strcpy(add->password,p->password);//copy paswd
		strcpy(add->userid,p->userid);//copy id
		add->permission=p->permission;//copy permi

		all->num_all++;//add num
		if(add->permission)
			all->num_su++;//add su num
		all->tail=add;// do tail
		visit=visit->next;//travel visit
	}
	fclose(fp);
	return all;
}

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
	cout<<"\n\n\n\n		============查询模式===========\n\n";
	cout<<"			1-查询学生信息\n"
		<<"			0-  退出输入0\n\n";
	cout<<"		===========>>>>>>>>>============\n\n";
	cout<<"选择一个功能---->>>>>>";
}
