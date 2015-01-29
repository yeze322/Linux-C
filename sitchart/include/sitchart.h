/*************************************************************************
	> File Name: sitchart.h
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 26 Jan 2015 12:43:57 UTC
 **********************************************************************
*/
#ifndef _SIT_H_
#define _SIT_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include "struct.h"
using namespace std;


//-----------crosslist.cpp------------------
node* createnode();
list* createlist();
nodehead* createnodehead();
//-----------readfromfile.cpp--------------
list* readfromfile();
void readone(FILE *fp,list *head);
//-----------print.cpp--------------
void printcol(list *head,int col);
void printrow(list *head,int row);
void printone(list *head,int row,int col);
void printaperson(list *head,char *name);
void printsitchart(list *);
//----------rebuild.cpp-------------
void sortrow(nodehead *head);
void sortcol(nodehead *head);
void rebuild(list *L);
//----------------------------------
#endif // !1


