#include <stdio.h>

int main(int argc, char *argv[])
{
	int year = 2015;
	printf("请输入年份(1990年之后)：");
	scanf_s("%d", &year);
	int year_1990 = 1990;
	int ryear = 0;
	for (int i = year_1990; i < year; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
			ryear++;
		}
	}

	//声明及初始化变量
	int m = 0;
	char *week[] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
	char *month_n[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int month_d[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int initial = ((year - year_1990)*365 + ryear)%7;
	int second = (initial+month_d[m])%7;
	int f_m,s_m;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		month_d[1] = 29;
	}

	printf("%40d\n\n", year);

	while (m < 12){
		f_m = 1;
		s_m = 1;

		//打印月份
		printf("%20s", month_n[m]);
		m++;
		printf("%43s", month_n[m]);
		m++;
		printf("\n");

		//打印星期抬头
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < 7; i++)
				printf("%4s ", week[i]);
			printf("     ");
		}

		//打印日期
		while (f_m <= month_d[m - 2] || s_m <= month_d[m - 1]){
			for (int i = 0; i < 7; i++){
				if (i != initial || f_m > month_d[m - 2]){
					printf("%4s ", "");
				}
				else{
					printf("%4d ", f_m);
					f_m++;
					initial++;
					initial %= 7;
				}
			}
			printf("     ");
			for (int i = 0; i < 7; i++){
				if (i != second || s_m > month_d[m - 1]){
					printf("%4s ", "");
				}
				else{
					if (s_m == month_d[m - 1]);
					printf("%4d ", s_m);
					s_m++;
					second++;
					second %= 7;
				}
			}
			printf("\n");
		}
		printf("\n");
		initial = (second + month_d[m - 1])%7;
		second = (initial + month_d[m])%7;
	}
	getchar();getchar();
}