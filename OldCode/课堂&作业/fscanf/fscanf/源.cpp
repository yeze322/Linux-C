#include<iostream>
using namespace std;
#include<stdio.h>
struct STU
{
	int id;
	char name[20];
	double score[5];
	int total;
	int sex;
	STU *next;
};

int main()
{
	FILE *open;
	open=fopen("input.txt","r");
	int q;char name[100]="";
	double a,b,c,d,e,f;

	STU temp;
	//fscanf(open,"%d%s%lf%lf%lf%lf%lf%lf",&q,name,&a,&b,&c,&d,&e,&f);
	fscanf(open,"%d%s%d%lf%lf%lf%lf%lf",&(temp.id),temp.name,&(temp.sex),\
		&(temp.score[0]),&(temp.score[1]),&(temp.score[2]),&(temp.score[3]),&(temp.score[4]));


	return 0;
}
