#ifndef _STDIO_H_
#define _STDIO_H
#include<iostream>
using namespace std;
#endif
const int N=16;
struct heap{
	int data;
	heap * left;
	heap * right;
}node[N],*head;

void CreateHeap(int a[N])
{
	head=&node[0];
	node->left=node->right=NULL;
	for(int i=0;i<N;i++)
	{
		node[i].data=a[i];
	}
	for(int i=0;i<N;i++)
	{
		if(node[i].data!=0)
		{
			if(2*i+1<N&&node[2*i+1].data!=0)
				node[i].left=&node[2*i+1];
			else
				node[i].left=NULL;
			if(2*i+2<N&&node[2*i+2].data!=0)
				node[i].right=&node[2*i+2];
			else
				node[i].right=NULL;
		}
	}
}//左右节点指向的指针有一个都为空

void displayheap1(heap *Head)
{
	if(Head!=NULL)
	{
		cout<<Head->data<<'/';
		displayheap1(Head->left);
		displayheap1(Head->right);
	}
}
void displayheap2(heap *Head)
{
	if(Head!=NULL)
	{
		displayheap2(Head->left);
		cout<<Head->data<<'/';
		displayheap2(Head->right);
	}
}
void swap(int &a,int &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}

void heapmax(heap *head)
{
	if(head==NULL)
		return;
	if(head->left==NULL&&head->right==NULL)
		return;
	heapmax(head->right);
	heapmax(head->left);
	int max=head->data;
	if(head->left!=NULL&&head->right!=NULL)
	{
		if(head->data>=head->left->data&&head->data>=head->right->data)
			return;
		head->right->data>head->left->data?swap(head->right->data,head->data):swap(head->left->data,head->data);
	}
	//if(head->right!=NULL)
	else if(head->right!=NULL&&head->left->data==NULL&&head->right->data>head->data)
		swap(head->right->data,head->data);
	else if(head->left!=NULL&&head->right->data==NULL&&head->left->data>head->data)
		swap(head->left->data,head->data);	
	return;
}//堆排序一般都是把一串数字排序，建立struct的意义好像不大啊
void heaptravel(heap *head)
{
	if(head==NULL)
		return;
	heapmax(head);
	heaptravel(head->left);
	heaptravel(head->right);
}
