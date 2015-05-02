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
	char *newc=(char *)malloc(sizeof(char)*strlen(a));
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
		//num[i/9]=num[i/9]*10+(a[i]-'0');//倒序的

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
	int *add=(int *)calloc(digit,sizeof(int));//这里会触发断点???当位数很长digit>=4的时候。//原因竟是在takeoffsign函数中使用了malloc？现在去掉就好了
	
	//符号位
	//int *flag=(int *)calloc(digit,sizeof(int));
	for(int i=0;i<digit;i++)
	{
		num1[i]=num1[i]*flag_a+num2[i]*flag_b+(i==0?0:add[i-1]);
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
		int value=num1[i]+1000000000;//num每小段是正序但是整体反向,结合下面的000开头，索性+1000000000

		itoa(value,temp,10);//如果是00000999形式，会出现问题，现在每个temp都多一个头1
		rotate(temp);temp[9]='\0';//变成999000000形式，再转一次就行
		rotate(temp);
		strcat(result,temp);

	}
	
	//去掉头0并添加符号位
	rotate(result);
	int i=strlen(result)-1;
	while(result[i]=='0'&&i>0)
		i--;
	if(change_sign)
		result[++i]='-';
	result[++i]='\0';
	rotate(result);
	return result;
}
int main()
{
	char a[]="-99999990798068769895123152432412419812123127951024709862187461298749999";
	char b[]="998464513313213123132165798796412315152321996465465465469999999999999";
	printf("%s\n +\n%s \n= \n",a,b);
	char* result=bignum(a,b);
	printf("%s\n",result);
	return 0;
}//bug
//1.断点BUG，takeoffsign里malloc去掉就解决了（原因还是不明白）//原因竟然是写成了sizeof。strlen才能正常使用

/*更深层次的原因：先malloc的指针p被分配一个地址，然后如果继续malloc一个q那么就会接着这片内存分配。
不过即使p和q都是1位，都会在p,q之间预留一块空间。导致写入内存的字符串较短的时候不会出现错误。而当溢出的部分足够长时，问题就来了。
假如先malloc的指针p没有预留好足够的空间却被赋一个超出空间的值（例如malloc（4）,却写入很大的字符串）
那么在malloc下一个指针q后，就会导致q被指向p中被覆盖的的那片内存，导致*p的内容错误*/

//2.全是0的时候itoa是null。加if判断手动添加00000000----已经整合到问题5中了。
//3.计算进位后，num要取余数存入
//4.flag_a、b的正负，加入else只计算大正数+小负数或正add正
//5.line 106附近，如果是一个000009999这样的数字，itoa会直接变成9999而不是000009999，所以把它+100000000再去掉首位