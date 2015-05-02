#include<iostream>
using namespace std;
const int N=16;
struct tree
{
	int data;
	tree *left;
	tree *right;
}node[N];//注意这里node[N]是无序的，只是为了方便建立了一个。

void CreateTree(int a[])
{	
	for(int i=0;i<N;i++)
		node[i].data=a[i];
	for(int i=0;i<N;i++)
	{
		if(node[i].data)
		{
			if(2*i+1<N&&node[2*i+1].data)
				node[i].left=&node[2*i+1];
			else;
				//node[i].left=NULL;
			if(2*i+2<N&&node[2*i+2].data)
				node[i].right=&node[2*i+2];
			else;
				//node[i].right=NULL;
		}
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