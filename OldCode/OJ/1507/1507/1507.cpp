#include<stdio.h>
int main()
{
	int a,b,a1,b1;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		while(1)
		{
			if(a>1000000||b>1000000||a<1||b<1)
				break;
			a1=a^b;
			b1=(a&b)<<1;
			a=a1;
			b=b1;
			if(a==0||b==0)
			{
				printf("%d\n",a|b);
				break;
			}
		}
	}
}
/*��Ŀ������
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
���룺
������ܰ����������������
����ÿ�����԰���������Ϊ��������m��n(1<=m,n<=1000000)��
�����
��Ӧÿ�����԰��������m+n��ֵ��
�������룺
3 4
7 9
���������
7
16*/