#include "BST.h"
#include "common.h"
using std::vector;

void* printfnode(Node* a,void* arg)
{
	std::cout<<a->val<<"==";
	return NULL;
}
/* use a struct to get class BST's infomation */
struct get {
	vector<int> left;
};
void* getNodeVal(Node*a, void* arg)
{
	((get*)arg)->left.push_back(a->val);
	return NULL;
}

/* == make sure destructor work == */
void makesuredestructorwork()
{
	int a[7] = {3,1,8,2,6,7,5};
	vector<int> num(a,a+7);
	BST tree1(num);	
	BST t2(tree1);
	tree1.inorderBST(printfnode,NULL);
	get tmp;
	tree1.inorderBST(getNodeVal,(void*)&tmp);
	
	t2=tree1;


	return ;
}

int main()
{
	makesuredestructorwork();
	return 0;
}