#ifndef _TREE_H_
#define _TREE_H_
#include<iostream>
#include "tree.h"
#endif
#include<stdio.h>
const int M=5;
int a[M]={1,2,4,5,3};
int b[M]={4,2,5,1,3};
int *queue=a;
//类似队列一样的变量，用来记录哪个值还未查询过。因为递归的问题不能在a[]中查找根节点值然后角标+1来作为下一个根节点值

tree* createnode_dynamic()
{
	tree *p=new tree;
	p->left=p->right=NULL;
	return p;
}//分配好新建立的内存的左右指针值，错误就迎刃而解了！

int FindValueInA(int array[],int find)
{
	for(int i=0;i<M;i++)
		if(array[i]==find)
			return i;
	return -1;
}

void DivideAndFind_Tree(tree *root,int top,int end)
{
	if(top>end)
		return;
	int root_in_a=FindValueInA(a,root->data);
	//如果不在a[]中返回值为-1，代表他是头结点，其右子树即为重建后的结果。
	int root_in_b=FindValueInA(b,root->data);
	if(root_in_a+1>=5)//数组超了，代表没有下一个了也就是查找完毕
	{
		//printf("return because next root do not exsist:\n");
		return;
	}
	int next_root_value=*queue;//int cut = find next root in top-end;
	int next_root_in_b=FindValueInA(b,next_root_value);
	tree* p=createnode_dynamic();//create a new memory
	if(next_root_in_b<root_in_b)//这句话使得所有的非头结点都在右侧了.如果更改FindValueInA的返回值为M可以变成左子树
	{
		root->left=p;
		root->left->data=next_root_value;
		queue++;
	}//if root.value in right, root->left=p;
	else if(next_root_in_b>root_in_b)
	{
		root->right=p;
		root->right->data=next_root_value;
		queue++;
	}//if root.value in left, root.right=p;
	else //if equal....I don't know
		return;
	DivideAndFind_Tree(p,top,next_root_in_b-1);
	DivideAndFind_Tree(p,next_root_in_b+1,end);
}
//初始节点划分域 错误！在其中加入两个递归.加递归不行。现在主函数中划分一次吧.理想方案是加头结点..竟然去掉那句就对了………………
//原值要用队列，不然递归回去会找错人
//都找完了，找不到next value，无意义循环