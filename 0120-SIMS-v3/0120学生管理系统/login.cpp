//登录选项。用于选择su还是guest
#include"_SIMS.h"
extern USRINFO *U;


char* getpassword()
{
	char *password=(char *)calloc(PSWDLEN,sizeof(char));
	char *p=password;
	char ps;int i=0;
	while(fflush(stdin),(ps=getch())!=EOF)
	{//如何实现关闭回显的同时能使用退格键？
		//i=p-password;
		if(8==ps)//退格
		{
			//putchar('!');
			if(p==password)
				continue;
			printf("\b \b");
			p--;//p='\0';
			continue;
		}
		if(/*ps=='#'||ps=='+'||*/13==ps)//回车
		{
			putchar('\n');
			break;
		}
		putchar('*');
		*p++=ps;
	}//为了方便默认su先
	*p='\0';
	return password;
}

void guestsmell();
void login()//StuInfo *L)
{
	int trytime=3;
again:
	system("cls");
	guestsmell();
	printLOGHEAD();
	char name[NAMELEN]="";
	cout<<"		User ID:";
	//cin>>name;
	if(scanf("%s",name)==EOF) return;
	if(strcmp("-1",name)==0)
		return;//输入-1退出
	cout<<"		Input Password:";
	char *password=getpassword();//free
	int iffind=SearchUSR(name,password);
	if(1==iffind)
	{
		free(password);
		SU_BLOCK();
		trytime=3;
		goto again;
	}else if(0==iffind)
	{
		free(password);
		GUS_BLOCK();
		trytime=3;
		goto again;
	}
	else
	{
		printf("\n用户信息错误！还剩%d次机会！",--trytime);
		system("pause");
		if(trytime==0)
			return;
		goto again;
	}

}

int SearchUSR(char *name,char *pass)//return 0 guest ; 1- su; -1 no user
{
	USR *find=U->head->next;
	while(find)
	{
		if(!strcmp(find->userid,name)&&!strcmp(find->password,pass))
			return find->permission;
		find=find->next;
	}
	return -1;
}

void dayinzhanghuliebiao()
{
	USR *visit=U->head->next;
	printf("\n		==========当前账户列表===========\n");
	while(visit!=NULL)
	{
		printf("		");
		for(int i=0;i<3&&visit!=NULL;i++)
		{
			printf("%5s",visit->userid);
			visit=visit->next;
		}
		printf("\n");
	}
	printf("\n		=================================\n");

}

void dayinUSR(USR *find)
{
	printf("		[1] 用户名 -- %s\n",find->userid);
	printf("		[2] 登录密码 -- %s\n",find->password);
	printf("		[3] 登录权限 -- ");printf(find->permission?"管理员":"普通账户");
	putchar('\n');putchar('\n');
}


void AddUSR()
{
addag:
	system("cls");
	dayinzhanghuliebiao();
	printf("\n\n\n		添加用户，按提示填写\n		=======================\n\n");
	cout<<"		输入要添加的用户名\n		[输入-1或^Z取消本次操作]:";
	fflush(stdin);
	char name[NAMELEN]="";
	//cin>>name;
	if(scanf("%s",name)==EOF) return;//Z
	if(strcmp("-1",name)==0) return;
	USR *visit=U->head->next;
	while(visit){if(strcmp(visit->userid,name)==0){
		printf("\n		用户已存在！");system("pause");goto addag;
	}visit=visit->next;}
	USR *ad=CreateUSR();
	U->num_all++;U->tail->next=ad;U->tail=ad;
	cout<<"\n		将要添加的用户名为 "<<name;
	cout<<" 输入密码：";char password[PSWDLEN]="";fflush(stdin);
	//cin>>password;
	if(scanf("%s",password)==EOF) goto addag;//Z
	strcpy(ad->password,password);
	strcpy(ad->userid,name);
	cout<<"\n		添加成功！默认为普通用户，如要提升权限在主菜单中管理！\n\n";
	dayinUSR(U->tail);
	RewirteLOGIN();
	system("pause");
	goto addag;
}

void DelUSR()
{
delag:
	system("cls");
	dayinzhanghuliebiao();
	printf("\n\n\n		删除用户，按提示填写\n		=======================\n\n");
	cout<<"		输入要删除的用户名[输入-1或^Z取消本次操作]:";
	fflush(stdin);
	char name[NAMELEN]="";
	//cin>>name;
	if(scanf("%s",name)==EOF) return;//Z
	if(strcmp("-1",name)==0) return;
	USR *visit=U->head;
	while(visit->next){
		if(strcmp(visit->next->userid,name)==0)
		{
			if(visit->next->permission==1)
			{
				printf("\n		管理员账户不允许删除！请先更改权限再操作！");
				system("pause");
				goto delag;
			}
			dayinUSR(visit->next);
			printf("\n		确认要删除该用户吗？y确认，其他键返回");
			char yi;fflush(stdin);
			//cin>>yi;
			if(scanf("%c",&yi)==EOF) goto delag;//Z
			if(yi!='y')
				goto delag;
			USR *record=visit->next->next;
			delete(visit->next);visit->next=record;
			U->num_all--;
			RewirteLOGIN();
			printf("\n		删除成功！");
			system("pause");goto delag;
		}
		visit=visit->next;
	}
	cout<<"\n		没有找到对应用户！";
	system("pause");goto delag;
}

void UpdateUSR()
{
geng:
	system("cls");
	dayinzhanghuliebiao();
	printf("\n\n\n		用户信息修改，按提示填写\n		=======================\n\n");
	cout<<"		输入要修改的用户名[输入-1或^Z返回上级菜单]:";
	fflush(stdin);
	char name[NAMELEN]="";
	//cin>>name;
	if(scanf("%s",name)==EOF) return;//Z
	if(strcmp("-1",name)==0)
		return;
	USR *visit=U->head->next;
	while(visit)
	{
		if(strcmp(visit->userid,name)==0)
		{
			char pass2[PSWDLEN]="";char pass1[PSWDLEN]="";char pass0[PSWDLEN]="";int permi;
			dayinUSR(visit);
			printf("\n		用户已找到！请输入希望修改的条目\n		[输入-1或^Z更换用户]:");
			int change;fflush(stdin);
			//cin>>change;
			if(scanf("%d",&change)==EOF) goto geng;//Z
			switch (change)
			{
			default:
				break;
			case -1:goto geng;
			case 1:
				printf("\n		希望修改用户名。输入新的用户名:");
				fflush(stdin);//cin>>pass1;
				if(scanf("%s",pass1)==EOF) goto geng;//Z

				cout<<"\n		用户名"<<visit->userid<<" 将修改为 "<<pass1<<" 是否继续? 继续输入y，其他返回！";
				fflush(stdin);//cin>>pass2;
				if(scanf("%s",pass2)==EOF) goto geng;//Z
				if(strcmp(pass2,"y")!=0)
					goto geng;
				strcpy(visit->userid,pass1);
				printf("\n		用户名修改成功！用户信息更新为：\n");
				RewirteLOGIN();
				dayinUSR(visit);system("pause");
				goto geng;
			case 2:
				printf("\n		希望修改密码。输入原密码:");
				fflush(stdin);//cin>>pass0;
				if(scanf("%s",pass0)==EOF) goto geng;//Z
				if(strcmp(pass0,visit->password)!=0)
				{
					printf("\n密码错误!");system("pause");
					goto geng;
				}
				printf("\n		验证成功！输入新后的密码：");
				fflush(stdin);//cin>>pass1;
				if(scanf("%s",pass1)==EOF) goto geng;//Z
				printf("\n		再次输入密码！");
				fflush(stdin);//cin>>pass2;
				if(scanf("%s",pass2)==EOF) goto geng;//Z
				if(strcmp(pass1,pass2)!=0)
				{
					printf("\n		两次输入不一致！");system("pasue");goto geng;
				}
				strcpy(visit->password,pass1);
				printf("\n		密码修改成功！用户信息更新为：\n");
				RewirteLOGIN();
				dayinUSR(visit);system("pause");
				goto geng;
			case 3:
				printf("\n		希望修改用户权限！\n		输入新的权限等级[1为管理员，0为普通账户]：");
				fflush(stdin);//cin>>permi;
				if(scanf("%d",&permi)==EOF) goto geng;//Z
				cout<<"\n		该用户的权限将被修改为 "<<permi;
				printf(permi?"管理员":"普通账户 ");
				cout<<" \n		是否继续? 继续输入y，其他返回！";
				fflush(stdin);//cin>>pass2;
				if(scanf("%s",pass2)==EOF) goto geng;//Z
				if(strcmp(pass2,"y")!=0)
					goto geng;
				visit->permission=permi;
				printf("\n		用户名修改成功！用户信息更新为：\n");
				dayinUSR(visit);
				RewirteLOGIN();
				system("pause");
				goto geng;
			}

		}
		visit=visit->next;
	}
	cout<<"\n		用户未找到！"<<endl;
	system("pause");
	goto geng;
	//printf("")
}

void ChaxunUSR()
{
bg:	
	system("cls");
	dayinzhanghuliebiao();
	printf("\n\n		-----------账户信息查询-----------\n\n");
	USR *find=U->head->next;
	printf("		输入要查询的用户名[输入-1或^Z退出]：");
	char name[NAMELEN]="";
	fflush(stdin);
	//cin>>name;
	if(scanf("%s",name)==EOF) return;
	if(strcmp(name,"-1")==0)
		return;
	while(find)
	{
		if(strcmp(find->userid,name)==0)
		{
			dayinUSR(find);
			system("pause");
			goto bg;
		}
		find=find->next;
	}
	printf("		\n没有找到用户信息！");system("pause");
	goto bg;
}


void printLOGHEAD()
{
	printf("\n\n");
	printf("		=============================================\n\n");
	printf("		  #######    #####       #   #      #######\n");
	printf("		  #            #        # # # #     #      \n");
	printf("		  #######      #       #   #   #    #######\n");
	printf("		        #      #      #    #    #         # \n");
	printf("		  #######    #####    #    #    #   #######\n\n");
	printf("		==========学生信息管理系统--by.夜泽==========\n");
	printf("		==============键入-1或^Z退出系统=============\n\n");
}

void guestsmell()
{
	printf("当前开放来宾账户为:");
	USR *find=U->head->next;
	while(find)
	{
		if(find->permission==0)
			break;
		find=find->next;
	}
	printf("%s",find->userid);
	printf(" 密码为：%s\n",find->password);
}
