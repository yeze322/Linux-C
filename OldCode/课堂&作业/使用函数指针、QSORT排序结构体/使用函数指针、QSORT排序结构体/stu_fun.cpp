#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "student.h"
#include<stdlib.h>
#include<stdio.h>
#endif // !_STUDENT_H_
void givevalue(STU &stu,int namenumber)
{
	stu.name=namenumber;
	stu.Math=rand()%150;
	stu.Eng=rand()%120;
	stu.Physics=rand()%100;
	stu.total=stu.Math+stu.Eng+stu.Physics;
}
int bigorsmall(PSTU a,PSTU b,int which)
{
	if(*((int*)(a)+which)>*((int*)(b)+which))
		return 1;
	//else if
}//未完成，先不写这么复杂的东西

void printitem(PSTU a,int people)
{
	printf("Rank  Name Total Eng Phy Math\n");
	for(int i=0;i<people;i++)
	{
		printf("%4d ",i+1);
		printf("%4c %4d %4d %4d %4d\n",a[i].name+'A',a[i].total,a[i].Math,a[i].Eng,a[i].Physics);
	}
}


int STUcmp(const void *left,const void *right)
{
	STU stu1,stu2;
	stu2=*(STU*)left;
	stu1=*(PSTU)right;
	if(stu1.total>stu2.total)
		return 1;
	else if(stu1.total<stu2.total)
		return -1;
	else
	{
		if(stu1.Math>stu2.Math)
			return 1;
		else if(stu1.Math<stu2.Math)
			return -1;
		else
		{
			if(stu1.Eng>stu2.Eng)
				return 1;
			else if(stu1.Eng<stu2.Eng)
				return -1;
			else
			{
				if(stu1.Physics>stu2.Physics)
					return 1;
				else if(stu1.Physics<stu2.Physics)
					return -1;
				else
				{
					if(stu1.name>stu2.name)
						return 1;
					else if(stu1.name<stu2.name)
						return -1;
				}

			}

		}
	}

}
