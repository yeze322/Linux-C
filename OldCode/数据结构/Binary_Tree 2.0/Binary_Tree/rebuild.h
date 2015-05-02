#ifndef _TREE_H_
#define _TREE_H_
#include "tree.h"
#endif
#include<stdio.h>
tree rebuild[N];
int rebuild_count=0;
const int M=5;
int a[M]={1,2,3,4,5};
int *queue=a;
int b[M]={3,2,5,4,1};
tree* createnode()
{
	tree *p=&rebuild[rebuild_count];
	rebuild_count++;
	return p;
}
tree* createnode_dynamic()
{
	tree *p=new tree;
	p->left=p->right=NULL;
	return p;
}//分配好新建立的内存的左右指针值，错误就迎刃而解了！
//看来最重要的还是开头的判断条件

int FindValueInA(int array[],int find)
{
	for(int i=0;i<M;i++)
		if(array[i]==find)
			return i;
	return -1;
}

void DivideAndFind_Tree(tree *root,int top,int end)
{
	cout<<"Divide in "<<top<<" to "<<end<<" root's value is :"<<root->data<<'\n';
	if(top>end)
	{
		printf("return because top>end\n");
		return;
	}
	/*if(root->data<0)
	{
		//root->data=*queue++;
		return;
	}*/
	int root_in_a=FindValueInA(a,root->data);
	//如果不在a[]中代表他是头结点，那么把它下一个节点设为a[0]
	int root_in_b=FindValueInA(b,root->data);
	//这句没用了。if(root_in_b==-1);
	if(root_in_a+1>=5)//数组超了，代表没有下一个了也就是查找完毕
	{
		printf("return because next root do not exsist:\n");
		return;
	}
	int next_root_value=*queue;//int cut = find next root in top-end;
	int next_root_in_b=FindValueInA(b,next_root_value);
	tree* p=createnode_dynamic();//create a new memory
	if(next_root_in_b<root_in_b)//这句话使得所有的非头结点都在右侧了！
	{
		root->left=p;
		root->left->data=next_root_value;
		queue++;
		cout<<"I create ["<<next_root_value<<"] in left, father is:["<<root->data<<"]\n";
	}//if root.value in right, root->left=p;
	else if(next_root_in_b>root_in_b)
	{
		root->right=p;
		root->right->data=next_root_value;
		queue++;
		cout<<"I create :["<<next_root_value<<"]in right, father is:["<<root->data<<"]\n";
	}//if root.value in left, root.right=p;
	else //if equal....I don't know
	{
		printf("return because next root = now root\n");
		return;
	}
	printf("next root's (%d) place in b is %d\n",next_root_value,next_root_in_b);
	printf("will divide %d -- %d && %d -- %d \n",top,next_root_in_b-1,next_root_in_b+1,end);
	DivideAndFind_Tree(p,top,next_root_in_b-1);
	DivideAndFind_Tree(p,next_root_in_b+1,end);
}
//初始节点划分域 错误！在其中加入两个递归.加递归不行。现在主函数中划分一次吧.理想方案是加头结点..竟然去掉那句就对了………………
//原值要用队列，不然递归回去会找错人
//都找完了，找不到next value，无意义循环