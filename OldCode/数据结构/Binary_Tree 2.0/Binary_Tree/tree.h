#ifndef _IOSTREAM_
#define _IOSTREAM_
#include<iostream>
#endif
using namespace std;
const int N=16;
struct tree
{
	int data;
	tree *left;
	tree *right;
}node[N];//注意这里node[N]是无序的，只是为了方便建立了一个，也可以用new的。
void CreateTree(tree &root,int value)
{
	root.data=value;
	root.left=root.right=NULL;
}//createtree(root,value,left&right)
void AddTree(tree &root,tree &leaf,bool choose,int value)//bool 0代表左子树，1代表右子树
{
	if(value==0)
	{
		(choose?root.right:root.left)=NULL;
		return;
	}
	(choose?root.right:root.left)=&leaf;
	leaf.data=value;
	leaf.left=leaf.right=NULL;
}
void AddTreeFromArray(int a[])
{
	int used=0,i=0;
	bool choose=0;
	//tree * queue[N];//想用队列来实现，不过对于完全二叉树，他是有规律的这一步先不写
	CreateTree(node[0],a[used++]);
	while(used<N-1)//我原本想在行16修改了边界条件，不过内存中未必是一个负值，还是考虑-1吧
	{
		AddTree(node[i],node[i*2+1],0,a[used++]);
		AddTree(node[i],node[i*2+2],1,a[used++]);
		i++;
	}

}
void VisitTree_1(tree &T)//可以调整前序遍历、中序遍历、后序遍历
//算法复杂度为O(n),递归工作栈的深恰好为树的高度。
{
	if(&T!=NULL)//我不加else设置为NULL竟然还可以正常判断？
	{
		cout<<T.data<<'/';
		VisitTree_1(*T.left);
		VisitTree_1(*T.right);
	}
}
void VisitTree_2(tree &T)
{
	if(&T!=NULL)
	{
		VisitTree_2(*T.left);
		cout<<T.data<<'/';
		VisitTree_2(*T.right);
	}
}
void VisitTree_3(tree *T)
{
	if(T!=NULL)
	{
		VisitTree_3(T->left);
		VisitTree_3(T->right);
		cout<<T->data<<'/';
	}
}