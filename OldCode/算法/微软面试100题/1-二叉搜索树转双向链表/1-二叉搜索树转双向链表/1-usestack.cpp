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

class bsearchtree{
public:
	struct node{
		int data;
		node *left;
		node *right;
		node(int x) : data(x),left(NULL),right(NULL) {}
	};
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
	{
		if(top==NULL)
			return;
		node *cutleft,*cutright;
		if(top->left==NULL&&top->right==NULL)
		{
			lefthead = top;
			righthead = top;
			return;
		}
		else if(top->left == NULL)
		{
			lefthead = top;
			ListWithoutStack(top->right,cutright,righthead);
			top->right=cutright;
			cutright->left=top;
		}
		else if(top->right == NULL)
		{
			righthead = top;
			ListWithoutStack(top->left,lefthead,cutleft);
			top->left = cutleft;
			cutleft->right = top;
		}
		else{
			ListWithoutStack(top->left,lefthead,cutleft);
			ListWithoutStack(top->right,cutright,righthead);
			top->right = cutright;
			cutright->left = top;
			top->left = cutleft;
			cutleft->right = top;
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
		inordervisit(top->left);       
		inordervisit(top->right);
		delete(top);
	}
};
int main()
{
	int a[10] = {5,1,2,3,4,6,7,8,9,10};    
	bsearchtree mt;
	bsearchtree::node *head = new bsearchtree::node(a[0]);
	for(int i=1;i<10;i++){
		mt.insert(head,a[i]);
	}
	cout<<"create success \n";
	mt.inordervisit(head);
	bsearchtree::node *bighead = NULL,*smallhead = NULL;
	//mt.createlist(bighead,smallhead);
	mt.ListWithoutStack(head,bighead,smallhead);
	//mt.destroy(head);
	return 0;
}
