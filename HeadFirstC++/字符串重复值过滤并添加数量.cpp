#include<stdio.h>
#include<string.h>
//原题来自于华为某次的上机题，需求相近
void main()
{
	char a[100];
	printf("Input a str:");
	gets(a);
	printf("size of a:%d\n",strlen(a));
	char out[108];
	int count[108]={0},length=0,had;
	//count[]是out[]中各个元素出现的次数的数组，length是out[]的长度；had的意义是检测是否和之前的相同
	for(int i=0;i<strlen(a);i++){
		had=0;
		for(int j=0;j<i;j++){
			if (out[j]==a[i]){
				count[j]++;
				had=1;
			}
			//count=count||(out[j]==a[i]);
		}
		if(had==0){
			out[length]=a[i];
			count[length]++;
			length++;//C数组从零开始的特性使得这里length既可以作为角标来赋值，也可以作为数组长度！
		}
	}
	printf("The numbers of characters:%d\nResult:",length);

	for(int i=0;i<length;i++){
		if(count[i]!=1)//if(count[i]可选（若想要把1个元素的数字也标出来的话。现在只出现1次的不显示数字）
			printf("[%d]",count[i]);
		printf("%c",out[i]);
	}
	printf("[end]\n");
	//out[]和count[]有明显的逻辑关系（一一对应），把他们做成结构体会更明确的表达意思？虽然这样没多大意义
	getchar();getchar();
}