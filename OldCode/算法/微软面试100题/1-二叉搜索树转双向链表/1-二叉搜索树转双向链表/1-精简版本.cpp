/*************************************************************************
> File Name: 1.cpp
> Author: Yeze
> Mail: a@b.com
> Created Time: 2015年02月09日 星期一 14时43分31秒
************************************************************************/
#include<assert.h>
#include<iostream>
#include<stack>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int x) : data(x),left(NULL),right(NULL) {}
};
class bsearchtree{
public:
	stack<node*> list;
	void insert(node *top,int x){
		if(top->data < x){
			if(top->right == NULL){
				top->right = new node(x);
				//cout<<"top->right = "<<top->right->data;
				return;
			}
			insert(top->right,x);
		}
		else{
			if(top->left == NULL){
				top->left = new node(x);
				//cout<<"top->left = "<<top->left->data;
				return;
			}
			insert(top->left,x);
		}
	}
	void inordervisit(node *top){
		if(top == NULL)
			return;
		inordervisit(top->left);
		cout<<top->data;
		list.push(top);
		inordervisit(top->right);
	}
	void ListWithoutStack(node *top,node *&lefthead,node *&righthead)
	{//正题部分。其他的都是构建二叉搜索树//contain it self is better
		if(top==NULL)
			return;
		node *cutleft,*cutright;
		lefthead = top;
		righthead = top;
		if(top->left){
			ListWithoutStack(top->left,lefthead,cutleft);
			top->left = cutleft;
			cutleft->right = top;
		}
		if(top->right){
			ListWithoutStack(top->right,cutright,righthead);
			top->right=cutright;
			cutright->left=top;
		}
	}
	void createlist(node *&bighead,node *&smallhead)
	{
		bighead = list.top();
		node *parent = list.top();
		parent->left = NULL;
		list.pop();
		while(!list.empty()){
			parent->right = list.top();
			list.top()->left = parent;
			parent = list.top();
			list.pop();
		}
		parent -> right = NULL;
		smallhead = parent;
	}
	void destroy(node *top){
		if(top == NULL)
			return;
		destroy(top->left);       
		destroy(top->right);
		delete(top);
		top=NULL;
	}
};
int main()
{
	int a[10] = {5,1,2,3,4,6,7,8,9,10};    
	bsearchtree mt;
	node *head = new node(a[0]);
	for(int i=1;i<10;i++){
		mt.insert(head,a[i]);
	}
	cout<<"create success \n";
	mt.inordervisit(head);
	node *bighead = NULL,*smallhead = NULL;
	//mt.createlist(bighead,smallhead);
	//mt.ListWithoutStack(head,bighead,smallhead);
	mt.destroy(head);
	//delete(head);
	//我用delete会出错，构造函数不是这么删除的，相关C++概念--拷贝构造函数
	//head=NULL;
	return 0;
}
