#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//#define SIZE 12
#include<string.h>
int main(int argc,char* argv[])//右键属性，命令参数中可以填写参数
{

	for(int i=0;i<argc;i++)
	{
		printf("argv[%d]:%s\n",i,argv[i]);
	}
	int SIZE=atoi(argv[1]);
	char **arr;
	arr=(char **)calloc(SIZE,sizeof(char**));
	char word[100];
	int count=0;
	while(memset(word,0,32),gets(word)!=NULL)//gets返回值是输入的指针
	{
		assert(count<SIZE);
		arr[count]=(char *)calloc(strlen(word)+1,sizeof(char));
		strcpy(arr[count],word);
		printf("%s\n",arr[count]);
		count++;
	}
	while(count-->=0)
	{
		free(arr[count]);
		arr[count]=NULL;
	}
	free(arr);arr=NULL;
	return 0;
}
