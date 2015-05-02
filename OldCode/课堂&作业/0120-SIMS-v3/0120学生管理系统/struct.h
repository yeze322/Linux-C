#include "_SIMS.h"
typedef int STU_ID;
typedef int STU_SEX;
typedef int STUCLASS;
typedef int STUNUM;

//typedef char* STU_NAME;
typedef double STU_SCORE ;

struct STU
{
	STU_ID id;
	char name[20];
	STU_SCORE score[5];
	STU_SCORE total;
	STU_SEX sex;
	STU *next;
};

struct StuInfo
{
	STU *head;
	STU *tail;
	//STUCLASS grades;
	STUNUM num;
};

STU* CreateSTU();
StuInfo* CreateInfo();
StuInfo* FileToInfo();
void RewriteFile();

void SearchSTU();

void printSTUINFO(STU*);


bool AddSTU();
void DelSTU();
void UpdateSTU();

void dayindangqianxuesheng();