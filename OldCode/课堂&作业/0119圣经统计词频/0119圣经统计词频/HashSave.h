#ifndef _FUN_
#define _FUN_

#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
struct node
{
	char word[30];
	int num;
	node *next;
};

struct Info
{
	node *head;
	node *tail;
	int words;
	int num;
};

node* CreateNode();
Info* CreateInfo();
void AddWord(Info *L,char *s);
bool IfExsist(Info *L,char *s);

void PrintResult(Info *L,FILE *write,int i);
void WordQsort(Info *L);
void PrintHash(Info **L,FILE*);

#endif // !_FUN_
