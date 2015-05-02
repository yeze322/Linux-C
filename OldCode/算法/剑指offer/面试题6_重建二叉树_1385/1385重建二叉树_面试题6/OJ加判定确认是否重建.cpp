#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//const int N=16;
typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}tree;
void VisitTree_3(tree *T)
{
	if(T!=NULL)
	{
		VisitTree_3(T->left);
		VisitTree_3(T->right);
		cout<<T->data<<' ';
		free(T);
	}
}
int M;
int* a=NULL;
int* queue=NULL;;
int* b=NULL;
tree* createnode_dynamic()
{
	tree *p=(tree*) malloc(sizeof(tree));
	p->left=p->right=NULL;
	return p;
}
int FindValueInA(int array[],int find)
{
	for(int i=0;i<M;i++)
		if(array[i]==find)
			return i;
	return -1;
}
bool ifright=1;
void DivideAndFind_Tree(tree *root,int top,int end,int fatherroot)
{
	if(top>end)
		return;
	int root_in_a=FindValueInA(a,root->data);
	int root_in_b;
	if(root->data!=-1)
		root_in_b=FindValueInA(b,root->data);
	else
		root_in_b=-2;
	if(root_in_a+1>=M)
		return;
	int next_root_value=*queue;
	if(root_in_b==-1)
	{
		ifright=false;
		return;
	}
	int next_root_in_b=FindValueInA(b,next_root_value);
	/*if((fatherroot<root_in_b&&fatherroot>next_root_in_b)||(fatherroot>root_in_b&&fatherroot<next_root_in_b))
	{
		ifright=false;
		return;
	}*/
	tree* p=createnode_dynamic();
	if(next_root_in_b<root_in_b)
	{
		root->left=p;
		root->left->data=next_root_value;
		queue++;
	}
	else if(next_root_in_b>root_in_b)
	{
		root->right=p;
		root->right->data=next_root_value;
		queue++;
	}
	else
		return;
	DivideAndFind_Tree(p,top,next_root_in_b-1,root_in_b);
	DivideAndFind_Tree(p,next_root_in_b+1,end,root_in_b);
	return;
}
int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&M)!=EOF)
	{
		a=(int*) malloc(sizeof(int)*M);
		b=(int*) malloc(sizeof(int)*M);
		queue=a;
		for(int i=0;i<M;i++)
			//scanf(p,"%d",&a[i]);
			cin>>a[i];
		for(int i=0;i<M;i++)
			//scanf(p,"%d",&b[i]);
			cin>>b[i];

		tree* head=createnode_dynamic();
		head->data=-1;

		DivideAndFind_Tree(head,0,M-1,-2);//把头结点的位置特殊化为-2
		if(ifright)
		{
			VisitTree_3(head->right);
			printf("\n");
		}
		else
			printf("No\n");
		free(a);a=NULL;
		queue=NULL;//queue根本没有申请空间，干嘛要free呢？犯错了
		free(b);b=NULL;
		free(head);head=NULL;
		ifright=1;//bool变量没置1！！！错误!
		//fflush(stdin);
	}
	return 0;
}
/*
一晚上快两小时的努力，终于AC了！
总结一下，首先把.h中的文件粘贴了过来，然后修改了边界条件。
对于边界条件集中在46行和传入的head节点的值为-2

后来的工作是解决动态的数组输入，然后遇到的问题为eruntime error
问题点是没有释放指针就再次给malloc空间了！
注意了new的反面是delete；malloc才是用delete！
然后问题又来了，运行到free的时候触发了断点，后来查证是queue指针的问题，没有malloc却free自然报错。

然后主要的工作是和输入做斗争，问题表现是：文件输入和手动输入的结果不一致！后来修改了bool变量在循结尾初始化，问题得以解决！
但是又想想，怎么会出现手动输入正确的现象？？？对啊这不对劲。反正结果就是添加了bool初始化的语句就AC了。

中间其他问题就是，fflush不能通过编译！
这次主要的收获在于free的更熟练运用，尤其是反复使用同一个变量名的时候。

总结一下，这个代码算是一点点凑起来的。
几天前写的重建二叉树，没想到在OJ上又遇见了，于是把原来的函数拿来用。
用了后才发现很多缺点，一是不能识别错误的二叉树，比如两个遍历元素根本不一样，这个通过return -1 修改head传入-2，并在root in b的赋值中加if条件解决
二是无法构建，这个在解决上面的问题后也得到了莫名其妙的解决，容我再想想。
想起来了，我在重建函数中添加了一个变量fatherroot，如果前一个节点夹在下一个节点和当前节点之间，那么就是错的！不过我给它注释掉了也能正常运行……容我再观测一下
逐句调试发现，root-》data是一个负值，fatherroot是1,top=0，end=7
说明这是第二次来找到1了，遍历重复了，又一次来到1,。如果是错误二叉树的话，未必会在根节点产生歧义，还是要用夹在中间好点吧？看看能不能AC
同样能AC，看来更严谨一些。
*/