#include<iostream>
using namespace std;
const int N=16;

struct tree
{
	int data;
	tree *left;
	tree *right;
}node[N];//注意这里node[N]是无序的，只是为了方便建立了一个。
tree leaves[N];
tree *p=leaves;
/*—————————————建立、添加部分—————————————————*/
void CreateTree(tree &root,int value)
{
	root.data=value;
	root.left=root.right=NULL;
}
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

/*—————————————二叉树重建部分—————————————————*/
//int a[9]={1,2,4,8,9,5,3,6,7};
//int b[9]={8,4,9,2,5,1,6,3,7};
int a[3]={1,2,3};
int b[3]={2,1,3};

tree * Find_Root(tree root,int top,int end)
	//明确函数的功能是什么：找到中序遍历数组中的最大的那个根节点并返回他的地址！
	//问题的关键在于如何设计指针的结构，将二叉树连接到一起？
	//设置了很多形参，希望能传入足够的信息。
{
	if(top>end)
	{
		cout<<"return!";
		return;
	}
	int former_root;//切分点,记录角标用的，找到传入的根节点值的角标，判断这段是左还是右
	for(int i=0;i<N;i++)
	{//find root.data in b[];
		if(root.data==b[i])
		{
			former_root=i;
			break;
		}
		else;
		//	return;//找不到了退出函数
	}
cout<<"(1) former_root:"<<former_root;
	bool choose;//then if right or left?;
	if(former_root<top)//等号呢？
		choose=1;//等于1则在右子树，等于0则在左子树
	else if(former_root==top||former_root==end)
	{
		cout<<"it happens ![equal]";//I don't know what happens.
	}
	else if(former_root>end)
		choose=0;
cout<<"(2) choose:"<<choose;
	//make sure the side;
	int next_root_value;//下一个根节点的值，通过a++类似的方式找到
	for(int i=0;i<N;i++)
	{
		if(a[i]==root.data)
		{
			next_root_value=a[i+1];
			break;
		}
	}//find next root in a[ ];
cout<<"(3) next_root_value"<<next_root_value;
	//-int next_root_value=a[next_root_mark];
	int cut;//把top to end 切分开的点
	for(int i=top;i<=end;i++)
	{
		if(b[i]==next_root_value)
			{
				cut=i;
				cout<<"(4) cut:"<<cut;
		}
		else
			cout<<"cut error!\n";
	}//find the position of next_root in b[ ]
	//tree leaf;
	tree *temp=new tree;
	root.right or left = temp;
	//以下代码脑子疯了的时候写的注意不要相信
	temp->data=b[cut];
	if(choose)
		temp->right=Find_Root(
	//AddTree(root,*++temp,choose,next_root_value);//root point to leaf(next_leaf);
	
	//Find_Root(*temp,top,cut-1);//root ->next_root, do top1 ~ end1;
	//Find_Root(*temp,cut+1,end);//root -> next root, do top2 ~ end2;
	return temp;
}




























/*—————————————从数组建立二叉树—————————————————*/
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
/*—————————————遍历部分——————————————————*/
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