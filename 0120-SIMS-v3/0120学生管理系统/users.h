#include "_SIMS.h"

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

struct USRINFO 
{
	USR *head;
	USR *tail;
	int num_all;
	int num_su;
};

USRINFO* FileToUSR();
void RewirteLOGIN();

USRINFO* CreateUSRINFO();
USR* CreateUSR();