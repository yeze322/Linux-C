#include<iostream>
using namespace std;
class arr_tree
{
public:
	int *arr;
	int length;
	arr_tree* father;
	arr_tree* son;
};//每个数组存到一个arr_tree里，内容包括数组地址arr，数组元素个数length,数组的上一个数组、数组的下一个数组

struct pointer
{
	int* p;
	arr_tree* belong;
};//因为要重载，指针用pointer装起来，p是真实的地址指向元素，belong用来标记p指到了哪个数组

pointer& operator++(pointer& pt)
{
	if(pt.p-pt.belong->arr==pt.belong->length-1)
	{
		if(pt.belong->son==NULL)
		{
			pt.p=NULL;
			return pt;
		}
		pt.p=pt.belong->son->arr;
		pt.belong=pt.belong->son;
	}
	else
		pt.p++;
	return pt;
}//重载++

pointer& operator--(pointer& pt)
{
	if(pt.p-pt.belong->arr==0)
	{
		if(pt.belong->father==NULL)
		{
			pt.p=NULL;
			return pt;
		}
		pt.p=pt.belong->father->arr+pt.belong->father->length-1;
		pt.belong=pt.belong->father;
	}
	else
		pt.p--;
	return pt;
}//重载--

pointer& operator+(pointer& pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		pt++;
	return pt;
}//重载+，没写好，会改变传入pointer的值，和++完全没差别
/*pointer& operator+(const pointer pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		temp++;
	return temp;
}*/
arr_tree* create_class(int a[],int length)
{
	arr_tree* node=new arr_tree;
	node->arr=a;
	node->length=length;;
	node->father=node->son=NULL;
	return node;
}//把数组放到arr_tree的初始化
void connect(arr_tree* node1,arr_tree* node2)
{
	node1->son=node2;
	node2->father=node1;
}//两个数组连接在一起。
void bubble(pointer,pointer);
int main()
{
	int a[10]={10,2,4,999,5,6,457,8,319,10};
	int b[9]={1,222,33,47};
	int c[4]={45,353,741,0};
	arr_tree *node_a=create_class(a,10);
	arr_tree *node_b=create_class(b,4);
	arr_tree *node_c=create_class(c,4);
	connect(node_a,node_b);
	connect(node_b,node_c);
	pointer tail;
	tail.p=c+node_c->length-1;
	tail.belong=node_c;
	pointer head;
	head.p=a;
	head.belong=node_a;
	bubble(head,tail);
	while(head.p!=NULL)
	{
		printf("%d ",*head.p);
		head++;
	}
	return 0;
}
//冒泡排序
void bubble(pointer head,pointer tail)
{//使用（head+1）会直接改变head的值，如何重载+号返回一个临时值?
	pointer top,next;
	top=head;
	for(pointer i=tail;i.p!=top.p;i--)
	{
		for(pointer j=top;j.p!=i.p;j++)
		{
			next=j+1;j--;
			if(next.p==NULL)
				break;
			if(*j.p>*next.p)
			{
				int temp=*j.p;
				*j.p=*next.p;
				*next.p=temp;
			}
		}
	}
}
//void quicksort(int a[],int top,int end)
//{//int top__pointer pt1\int end__pointer pt2
//	if(top>end)
//		return;
//	int flag=a[top];
//	int head=top,tail=end;	
//	while(head<tail)
//	{
//		while(a[tail]>=flag&&head<tail)
//			tail--;
//		a[head]=a[tail];
//		while(a[head]<=flag&&head<tail)
//			head++;
//		a[tail]=a[head];
//	}
//	a[tail]=flag;
//	quicksort(a,top,tail-1);
//	quicksort(a,tail+1,end);
//}