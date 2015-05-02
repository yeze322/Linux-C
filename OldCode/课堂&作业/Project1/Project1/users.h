//guestΩÁ√Ê
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define NAMELEN 20
#define PSWDLEN 20
void GUS_BLOCK();//StuInfo *);
void GUS_PRINT();

void SU_PRINT();
void SU_BLOCK();//StuInfo *);

struct USR
{
	bool permission;
	char userid[NAMELEN];
	char password[PSWDLEN];
	USR *next;
};

USR* CreateUSR()
{
	USR *p=new USR;
	p->next=NULL;
	p->permission=0;
	return p;
}

struct USRINFO 
{
	USR *head;
	USR *tail;
	int num_all;
	int num_su;
};

USRINFO* CreateUSRINFO()
{
	USRINFO *p=new USRINFO;
	p->head=CreateUSR();
	p->tail=p->tail;
	p->num_all=p->num_su=0;
	return p;
}


USRINFO* FileToUSR()
{
	FILE *fp=fopen("USERS.txt","r");
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
