#include<stdio.h>
#include<iostream>
int main()
{
	freopen("outout.txt","r",stdin);
	freopen("tutput.txt","w",stdout);

	char key='!';
	char c;
	while((c=getchar())!=EOF)
	{	
		c=c^key;
		putchar(c);
	}
	//FILE *fin2,*fout2;

	//fin2=fopen("output.txt","rb");
	//fout2=fopen("translate.txt","wb");
	//while(c=fgetc(fin2)!=EOF)
	//{	
	//	//c=c^key;
	//	fputc(c,fout2);
	//}
	//fclose(fin2);
	//fclose(fout2);
	return 0;
}
