typedef struct student
{
	int name;
	int Math;
	int Eng;
	int Physics;
	int total;
}STU,*PSTU;
void givevalue(STU&,int);
int STUcmp(const void *,const void *);
void printitem(PSTU,int);