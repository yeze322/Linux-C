#include "users.h"

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
		if('\0'==ps)
			continue;
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

int main()
{
	USRINFO *U=FileToUSR();
	char *p=getpassword();
	return 0;
}








/*int a=4,b=1;
void (*p)(int,int);
p=(void (*)(int,int))(dowswitch('b'));
p(a,b);*/