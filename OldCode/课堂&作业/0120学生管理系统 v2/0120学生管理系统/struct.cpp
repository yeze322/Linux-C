#include "_SIMS.h"

extern StuInfo *L;

STU* CreateSTU()
{
	STU *p=new STU;
	p->next=NULL;
	memset(p->score,0,5*sizeof(double));
	p->total=0;
	p->name[0]='\0';
	return p;
}

StuInfo* CreateInfo()
{
	StuInfo *p=new StuInfo;
	p->head=CreateSTU();
	p->tail=p->head;
	p->num=0;
	return p;
}

StuInfo* FileToInfo()
{
	FILE *open;
	open=fopen("STU_INFO.txt","r");
	StuInfo *L=CreateInfo();
	STU temp;
	STU *read;
	read=L->head;
	double a=1.0*1.0;
	while(fscanf(open,"%d%s%d%lf%lf%lf%lf%lf",&(temp.id),temp.name,&(temp.sex),&(temp.score[0]),\
		&(temp.score[1]),&(temp.score[2]),&(temp.score[3]),&(temp.score[4]))==8)
	{
		STU *p=CreateSTU();
		p->id=temp.id;
		p->sex=temp.sex;
		strcpy(p->name,temp.name);
		double sum=0;
		for(int i=0;i<5;i++)
		{
			sum+=temp.score[i];
			p->score[i]=temp.score[i];
		}
		p->total=sum;
		L->num++;
		read->next=p;
		L->tail=p;
		read=read->next;
	}
	fclose(open);
	return L;
}

void SearchSTU_ID()
{

	int id;
conti:	while(system("cls"),fflush(stdin),cout<<"\n\n		按学号查询学生信息!\n",dayindangqianxuesheng(),
			cout<<"\n		输入学生ID(输入-1退出):",scanf("%d",&id)==1)
		{
			fflush(stdin);
			if(id==-1)
				return;
			STU *search;
			search=L->head->next;
			while(search!=NULL)
			{
				if(search->id==id)
				{
					printSTUINFO(search);
					system("pause");
					goto conti;
				}
				search=search->next;
			}
			printf("		没有找到结果!\n");
			system("pause");
			/*printf("		3");
			_sleep(1000);printf(" 2");
			_sleep(1000);printf(" 1");
			_sleep(1000);*/
		}
}
void SearchSTU_NAME()
{

	char name[NAMELEN]="";
conti:	while(system("cls"),fflush(stdin),cout<<"\n\n		按姓名模糊查询学生信息!\n",dayindangqianxuesheng(),
			cout<<"\n		输入姓名(输入-1退出):",scanf("%s",name)==1)
		{
			fflush(stdin);
			if(strcmp(name,"-1")==0)
				return;
			printf("	ID          姓名  性别  科目1  科目2  科目3  科目4  科目5\n");
			STU *visit;
			visit=L->head->next;
			int count=0;
			while(visit!=NULL)
			{
				if(strstr(visit->name,name)!=NULL)
				{
					count++;
					printf("	%d  ",visit->id);
					printf("%15s ",visit->name);
					printf(visit->sex?"男 ":"女 ");
					for(int i=0;i<5;i++)
					{
						printf("%6.1lf ",visit->score[i]);
					}
					printf("\n");				
				}
				visit=visit->next;
			}
			printf("\n\n		》》》》》》查询结束》》》》》\n\n		找到[%d]条结果。",count);
			system("pause");
		}
}

void printALLSTU(int lie)
{
	STU *visit=L->head->next;
	int count=L->num;
	printf("\n\n	ID          姓名  性别  科目1  科目2  科目3  科目4  科目5\n");
	while(visit)
	{
		printf("	%d  ",visit->id);
		printf("%15s ",visit->name);
		printf(visit->sex?"男 ":"女 ");
		for(int i=0;i<5;i++)
		{
			printf("%6.1lf ",visit->score[i]);
		}
		printf("\n");
		visit=visit->next;
	}
	system("pause");
}


void SearchSTU()
{
bg:
	system("cls");
	cout<<"\n\n\n\n		=========学生信息查询========\n\n";
	cout<<"			1-按学号\n"
		<<"			2-按姓名\n"
		<<"			3-打印学生列表\n"
		<<"			4-打印全部学生信息\n"
		<<"			0-返回上级菜单\n";
	cout<<"		===========================\n\n		输入一个命令_____";
	int choose;
	fflush(stdin);
	cin>>choose;
	switch (choose)
	{
	default:goto bg;
	case 1:	SearchSTU_ID();goto bg;
	case 2: SearchSTU_NAME();goto bg;
	case 0: return;
	case 3: dayindangqianxuesheng();system("pause");goto bg;
	case 4: printALLSTU(3);goto bg;
	}
	goto bg;
}


void DelSTU()
{
st:	system("cls");
	dayindangqianxuesheng();
	printf("	输入要删除的学生学号(输入-1退出):");
	int id;
	cin>>id;
	if(id==-1)
		return;
	STU *find=L->head;
	while(find->next)
	{
		if(find->next->id==id)
		{
			printSTUINFO(find->next);
			printf("是否要删除该学生信息？y键确认删除，其他键返回。");
			char del;
			fflush(stdin);
			cin>>del;
			if(del!='y')
				goto st;
			STU *temp=find->next->next;
			delete(find->next);
			find->next=temp;
			RewriteFile();
			printf("修改成功！");printf("按任意键退出！\n\n");
			fflush(stdin);
			getchar();
			printf("3");
			_sleep(1000);printf(" 2");
			_sleep(1000);printf(" 1");
			_sleep(1000);
			return;
		}
		find=find->next;
	}
	printf("没有找到相应信息！\n");
	system("pause");
	goto st;
}


void UpdateSTU()
{
	int id;
again:
	while(fflush(stdin),system("cls"),printf("信息管理-》修改信息\n"),\
		dayindangqianxuesheng(),\
		printf("输入要修改的学生学号(-1退出)："),scanf("%d",&id)==1)
	{
		if(id==-1)
			return;
		STU *find=L->head->next;
		while(find!=NULL)
		{
			if(find->id==id)
			{
				int gd;
				printSTUINFO(find);
				while(fflush(stdin),printf("\n输入想要修改的项目[1-8]	输入-1退出: \n",id),scanf("%d",&gd)==1)
				{
					if(gd<=8&&gd>=4)
					{
						printf("希望修改条目为——	[%d] 科目 %d -- %3.1f\n输入新的成绩:",gd,gd-3,find->score[gd-4]);
						double grade;
						cin>>grade;
						printf("原成绩为 %3.1lf, 希望修改为 %3.1lf. 确认输入y,其他键退出！\n",find->score[gd-4],grade);
						char makesure;
						cin>>makesure;
						if(makesure!='y')
							continue;
						find->score[gd]=grade;
						printf("成绩已更新！\n");
						RewriteFile();
						printf("修改成功！\n");
						printSTUINFO(find);
						printf("按任意键退出！\n\n");
						fflush(stdin);
						getchar();
						printf("3");
						_sleep(1000);printf(" 2");
						_sleep(1000);printf(" 1");
						_sleep(1000);
						goto again;
					}
					else if(gd==-1)
						return;
					else if(gd==2)//姓名
					{
						printf("希望修改条目为——	[2] 姓名 -- %s\n输入新的姓名：",find->name);
						char namenew[20]="";
						fflush(stdin);
						cin>>namenew;
						printf("原姓名 %s 希望修改为 %s 确认输入y,其他键退出！\n",find->name,namenew);
						char makesure;
						cin>>makesure;
						if(makesure!='y')
							continue;
						strcpy(find->name,namenew);
						printf("姓名已更新！\n");
						RewriteFile();
						printf("修改成功！\n");
						printSTUINFO(find);
						printf("按任意键退出！\n\n");
						fflush(stdin);
						getchar();
						printf("3");
						_sleep(1000);printf(" 2");
						_sleep(1000);printf(" 1");
						_sleep(1000);
						goto again;
					}
					else if(gd==3)//性别
					{
						printf("希望修改条目为——\n		[3] 性别 -- %s：",find->name);
						printf("\n将把原性别 - ");printf(find->sex?"男":"女");
						printf(" - 修改为 - ");	printf(!find->sex?"男":"女");
						printf("\n确认输入y,其他键退出！\n");
						char makesure;
						fflush(stdin);
						cin>>makesure;
						if(makesure!='y')
							continue;
						find->sex=!find->sex;
						printf("性别已更新！\n");
						RewriteFile();
						printf("修改成功！\n");
						printSTUINFO(find);
						printf("按任意键退出！\n\n");
						fflush(stdin);
						getchar();
						/*printf("3");
						_sleep(1000);printf(" 2");
						_sleep(1000);printf(" 1");
						_sleep(1000);*/
						goto again;
					}

					else
						printf("输入错误！重新输入！\n");
				}
			}
			find=find->next;
		}
		printf("没有找到该学生！\n\n");
		system("pause");
	}
}

void RewriteFile()
{
	FILE *re=fopen("STU_INFO.txt","w");
	STU *visit=L->head->next;
	while(visit!=NULL)
	{
		fprintf(re,"%d  %s  %d ",visit->id,visit->name,visit->sex);
		for(int i=0;i<5;i++)
		{
			fprintf(re," %.1lf",visit->score[i]);
		}
		fprintf(re,"\n");
		visit=visit->next;
	}
	fclose(re);
	return;
}

void printSTUINFO(STU *man)
{
	printf("		=======================\n\n");
	printf("		学生当前信息：\n");
	printf("		[1] 学号 -- %d\n",man->id);
	printf("		[2] 姓名 -- %s\n",man->name);
	printf("		[3] 性别 -- %s\n",man->sex?"男":"女");
	for(int i=0;i<5;i++)
		printf("		[%d] 科目%d -- %3.1lf\n",4+i,i+1,man->score[i]);
	printf("		=======================\n\n");
}

void AddSTU()
{
ag:	system("cls");
	printf("		添加学生信息\n");
	dayindangqianxuesheng();
	printf("按步骤输入。学号输入-1退出：\n");
	STU *p=CreateSTU();
	printf("		[1] 学号 -- ");
	fflush(stdin);
	if(scanf("%d",&p->id)==EOF)
		goto bye;
	if(p->id==-1)
		goto bye;
	STU *find=L->head->next;
	while(find)//确定没有加过
	{
		if(find->id==p->id)
		{
			printf("		ERROR！！ 该学生存在，不能重复添加！\n");
			system("pause");
			goto ag;
bye:		fflush(stdin);
			delete(p);
			return;
		}
		find=find->next;
	}

	printf("		[2] 姓名 -- ");
	cin>>p->name;
	printf("		[3] 性别(男=1,女=0) -- ");
	cin>>p->sex;
	for(int i=0;i<5;i++)
	{
		printf("		[%d] 科目%d -- ",4+i,i+1);
		cin>>p->score[i];
	}
	printf("\n\n		添加成功！新添加的学生信息是：\n\n");
	printSTUINFO(p);
	printf("撤销操作输入 N,其他键继续！——");
	fflush(stdin);
	char ch;
	cin>>ch;
	if(ch=='N')
		goto bye;
	L->num++;
	L->tail->next=p;
	L->tail=p;
	RewriteFile();
	system("pause");
	return;
}

void dayindangqianxuesheng()
{
	printf("		=========================\n		  当前学生列表——\n");
	STU *search;
	search=L->head->next;
	while(search!=NULL)
	{
		printf("  		");
		for(int i=0;i<5&&search!=NULL;i++)
		{
			printf("%4d",search->id);
			search=search->next;
		}
		printf("\n");
	}
	printf("		=========================\n\n");
}
