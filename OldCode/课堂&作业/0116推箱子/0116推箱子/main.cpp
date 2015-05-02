#include "box.h"
int main()
{
	char c;
clc:system("cls");
	init();
	display();
	while((c=getchar())!=EOF)
	{
		system("cls");
		if(c=='a'||c=='s'||c=='d'||c=='w')
			manwalk(c);
		else if(c=='-')
			goto clc;
		else
			display();
	}
	return 0;
}
