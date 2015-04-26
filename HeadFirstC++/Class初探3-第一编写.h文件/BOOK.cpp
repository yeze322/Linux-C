#include "BOOK.h"
#include<iostream>
#include<string.h>
using namespace  std;
void book::initbook()
{
	char A[60];
	cout<<"Input book name:";
	cin>>A;
	strcpy(title,A);
	strcpy(author,"Mr.Amir");
	price=24.12;
	return;
}
void book::showbook()
{
	cout<<"Title:"<<title<<"\n"<<"Author:"<<author<<"\n"<<"Price:$"<<price<<"\n";
	return;
}