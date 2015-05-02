#include<stdio.h>  
int get_first_bit(int num)  
{  
    return num&~(num-1);  
}  
void get_two_unique_num(int *a,int n,int *num1,int *num2)  
{  
    int result_code=0,i;  
    for(i=0;i<n;i++)  
        result_code^=a[i];  
    int diff=get_first_bit(result_code);  
    *num1=0;  
    *num2=0;  
    for(i=0;i<n;i++)  
    {  
        if(a[i]&diff)  
        {  
            (*num1)^=a[i];  
        }  
        else  
        {  
            (*num2)^=a[i];  
        }  
    }  
}  
void get_three_unique_num(int *a,int n,int *num1,int *num2,int *num3)  
{  
    int result_code=0,i;  
    for(i=0;i<n;i++)  
        result_code^=a[i];  
    int flag=0;  
    for(i=0;i<n;i++)  
        flag^=get_first_bit(result_code^a[i]);  
    flag=get_first_bit(flag);  
    *num1=0;  
    for(i=0;i<n;i++)  
    {  
        if(get_first_bit(result_code^a[i])==flag)  
        {  
            (*num1)^=a[i];  
        }  
    }  
    for(i=0;i<n;i++)  
    {  
        if(a[i]==(*num1))  
        {  
            int temp=a[i];  
            a[i]=a[n-1];  
            a[n-1]=temp;  
            break;  
        }  
    }  
    get_two_unique_num(a,n-1,num2,num3);  
}  
void main()  
{  
    int a[]={2,2,4,4,6,6,3,5,7};  
    int num1,num2,num3;  
    get_three_unique_num(a,sizeof(a)/sizeof(int),&num1,&num2,&num3);  
    printf("%d\t%d\t%d\n",num1,num2,num3);  
	getchar();
}
