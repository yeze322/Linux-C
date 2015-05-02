#include<stdio.h>

typedef struct LinkList
{
	int data;
	LinkList *next;
}node;


void reverse(node *head)
{
	if(head->next==NULL||head->next->next==NULL)
		return;
	node *visit=head->next;
	node *p,*q,*r;
	p=head->next;
	q=head->next->next;
	while(q)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	head->next=q;
}