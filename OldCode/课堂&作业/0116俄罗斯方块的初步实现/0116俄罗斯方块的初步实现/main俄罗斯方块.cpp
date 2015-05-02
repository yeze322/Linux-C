#include "bricks.h"
#include<conio.h>
//#include<windows.h>
int main()
{
	bool q=0,e=0;
	int count=0;
	int which=0;
	while(1)
	{
		//if(getchar()=='\n')
		{
			BasicBrick(count/2,count%3,which);
			if(count==3)
				count=0;
			else
				count++;
		}
		_sleep(500);
		system("cls");
	}
	/*BasicBrick(0,0);
	BasicBrick(0,1);
	BasicBrick(1,0);
	BasicBrick(1,1);*/
	return 0;
}
