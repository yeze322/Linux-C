#include<stdio.h>
#include<string.h>

void remove(char *mainstr, char* substr)
{
again:
	char *find=strstr(mainstr,substr);
	if(find==NULL)
		return;
	*find='\0';
	find=find+strlen(substr);
	strcat(mainstr,find);
	goto again;
}


int main()
{
	char mainstr[999]="";
	char substr[999]="";
ff:	gets(mainstr);
	gets(substr);

	remove(mainstr,substr);
	puts(mainstr);

	goto ff;
}
