#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char* charp;
char str[]="hello";
const charp p=str;
charp const q=str;


const int n=10;
int main()
{
	printf("%d",sizeof(int*));
	return 0;
}

