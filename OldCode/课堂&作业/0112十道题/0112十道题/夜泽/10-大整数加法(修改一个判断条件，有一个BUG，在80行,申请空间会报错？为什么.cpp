#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void rotate(char str[])
{
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp;
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
}
char* takeoffsign(char a[])
{
	char *newc=(char *)malloc(10*sizeof(char));
	if(a[0]=='-')
	{
		rotate(a);
		a[strlen(a)-1]='\0';
		rotate(a);
	}
	else if(a[0]=='+')
	{
		rotate(a);
		a[strlen(a)-1]='\0';
		rotate(a);
	}
	strcpy(newc,a);
	return newc;
}
int* dividenum(char a[],int digit)//把大数切成int9位范围内的char，然后存储到int
{
	int *num=(int *)calloc(digit,sizeof(int));
	rotate(a);
	int count=1;
	for(int i=0;i<strlen(a);i++)
	{
		if(count==1000000000)
			count=1;
		num[i/9]=num[i/9]+count*(a[i]-'0');//正序的
		count*=10;
	}
	return num;
}

char* bignum(char a[],char b[])
{
	bool change_sign=0;//纪录是否要反号

	int flag_a=1,flag_b=1;//符号位
	if(a[0]=='-')
		flag_a=-1;
	if(b[0]=='-')
		flag_b=-1;//因为后面的add部分设计，不能完成两个大的负数，所以都转换成大整数加小负数或者正+正
	a=takeoffsign(a);b=takeoffsign(b);
	int len_a=strlen(a);
	int len_b=strlen(b);
	if(flag_a==-1&&flag_b==-1)
	{
		change_sign=true;
		flag_a=flag_b=1;
	}
	else if(flag_a==-1&&strlen(a)>strlen(b)||(flag_b==-1&&strlen(b)>strlen(a)))//当一正一副、负数绝对值大
	{
		change_sign=true;
		flag_a=-flag_a;
		flag_b=-flag_b;
	}
	else if((flag_a==-1&&strlen(a)==strlen(b)&&strcmp(a,b)==1)||(flag_b==-1&&strlen(a)==strlen(b)&&strcmp(b,a)==1))//一正一副，位数还相等，判断负的绝对值大
	{
		change_sign=true;
		flag_a=-flag_a;
		flag_b=-flag_b;
	}
	/*_________________________________*/
	int digit=(len_a>len_b?(len_a/9+1):(len_b/9+1));//划分成每9位一个的加法,这样就能做加法
	int *num1=dividenum(a,digit);
	int *num2=dividenum(b,digit);
	int *add=(int *)calloc(digit,sizeof(int));//这里会触发断点???当位数很长digit>=4的时候。
	
	//符号位
	//int *flag=(int *)calloc(digit,sizeof(int));
	for(int i=0;i<digit;i++)
	{
		num1[i]=num1[i]*flag_a+num2[i]*flag_b;
		add[i]=num1[i]/1000000000;
		num1[i]=num1[i]%1000000000;//忘记取余数
		if(num1[i]<0)
		{
			num1[i]=1000000000+num1[i]%1000000000;//借位
			add[i]++;//因为借位还要再借1次
		}
	}
	char *result=(char *)calloc(10000,sizeof(char));
	char temp[11];
	for(int i=digit-1;i>=0;i--)
	{
		int value=num1[i]+(i==0?0:add[i-1]);
		if(value!=0)
		{
			itoa(value,temp,10);
			strcat(result,temp);
		}
		else
			strcat(result,"000000000");
	}
	//去掉头0；
	rotate(result);
	int i=strlen(result)-1;
	while(result[i]=='0'&&i>0)
		i--;
	if(change_sign)
		result[++i]='-';
	result[++i]='\0';
	rotate(result);
	printf("%s\n",result);
	return result;
}
int main()
{
	char a[]="99999999999999999999999999999999999999999999999999999999999999999999";
	char b[]="99999999999999999999999999999999999999999999999999999999999999999999";
	printf("%s add %s equals :\n",a,b);
	char* result=bignum(a,b);
	return 0;
}//bug