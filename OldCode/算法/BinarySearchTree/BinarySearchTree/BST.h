#include "common.h"
using std::vector;
/* Node Struct */
struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x): val(x),left(NULL),right(NULL) {};
};
class BST;
typedef void* (BST::*BSTFUN)(Node*);
typedef void* (*funct)(Node*,void*);

/*- - - class BST - - -*/
class BST {
private:
	inline void insertNode(Node&,Node&);
	void inorderBST(Node* head);
	void _deleteBST(Node* head);
	//BSTFUN fun;
	void inorderBST();
	void inorderBST(Node*,funct,void*);
	/* 可选函数 */
	//static void* BST::printNode(Node *a) {std::cout<<a->val<<" ";return NULL;}//static here is importent!
	void* getAllNode(Node *a) {sortedTree.push_back(a);return NULL;}
	void* deleteAllNode(Node *a) {delete a;return NULL;}

	//注意这里。调用default constructor时，这个函数并没有创建.所以在构造函数内调用虽然成功但无效果。如果声明为static则可用
public:
	Node* head;
	vector<Node*> sortedTree;
	void inorderBST(funct,void*);
	BST():head(NULL){};
	BST(const vector<int>&);
	~BST();
};
/* ----- */

/* constructor and destructor */
BST::~BST()
{
	_deleteBST(head);
}
BST::BST(const vector<int>&num)
{
	if(num.size()==0){
		std::cout<<"Create Tree Failed, NULL Input!\n";
		return;
	}
	Node *put = new Node(num[0]);
	//fun = &getAllNode;
	sortedTree.push_back(put);
	head = put;
	for(unsigned int i=1;i<num.size();i++)
	{
		put = new Node(num[i]);
		insertNode(*head,*put);
		//printNode(put);
	}
	inorderBST();
}
/* ----- */

/* insert new node */
void BST::insertNode(Node& root,Node& put)
{
	if(put.val<=root.val){
		if(root.left==NULL)
			root.left = &put;//I can't add const because there
		else
			insertNode(*root.left,put);
	}else{
		if(root.right==NULL)
			root.right = &put;
		else
			insertNode(*root.right,put);
	}
}
/* ----- */

/* inorder visit BST */
void BST::inorderBST()
{
	if(head==NULL)
		return;
	inorderBST(head->left);
	this->getAllNode(head);
	inorderBST(head->right);
	std::cout<<std::endl;
}
void BST::inorderBST(Node* head)
{
	if(head==NULL)
		return;
	inorderBST(head->left);
	this->getAllNode(head);
	inorderBST(head->right);
}
void BST::_deleteBST(Node* head)
{
	if(head==NULL)
		return;
	_deleteBST(head->left);
	_deleteBST(head->right);
	this->deleteAllNode(head);
}
void BST::inorderBST(funct fun,void* argument)
{
	if(head==NULL)
		return;
	inorderBST(head->left,fun,argument);
	fun(head,argument);
	inorderBST(head->right,fun,argument);
}
void BST::inorderBST(Node* head,funct fun,void* argument)
{
	if(head==NULL)
		return;
	inorderBST(head->left,fun,argument);
	fun(head,argument);
	inorderBST(head->right,fun,argument);
}
/* ----- */
/* operator: '=' must reload, if class 1 = class 2, it will be deleted twice */