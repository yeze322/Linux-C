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

/*pointer& operator+(pointer& pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		pt++;
	return pt;
}//重载+，没写好，会改变传入pointer的值，和++完全没差别*/

pointer& operator+(const pointer pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		temp++;
	return temp;
}
pointer& operator-(const pointer pt,int i)
{
	pointer temp=pt;
	for(int j=0;j<i;j++)
		temp--;
	return temp;
}

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
void quicksort(pointer,pointer);
int main()
{
	int a[5]={10,9,8,7,6};
	int b[9]={5,4,3,2,1};
	//int c[4]={45,353,741,0};
	arr_tree *node_a=create_class(a,5);
	arr_tree *node_b=create_class(b,5);
	//arr_tree *node_c=create_class(c,4);
	connect(node_a,node_b);
	//connect(node_b,node_c);
	pointer tail;
	tail.p=b+node_b->length-1;
	tail.belong=node_b;
	pointer head;
	head.p=a;
	head.belong=node_a;
	quicksort(head,tail);
	while(head.p!=NULL)
	{
		printf("%d ",*head.p);
		head++;
	}
	return 0;
}
//冒泡排序
void bubble(pointer head,pointer tail)
{//使用（head+1）会直接改变head的值，已经修改重载
	pointer top,next;
	top=head;
	for(pointer i=tail;i.p!=top.p;i--)
	{
		for(pointer j=top;j.p!=i.p;j++)
		{
			next=j+1;
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
void quicksort(pointer TOP,pointer END)
{//int top__pointer pt1\int end__pointer pt2
	if(TOP.p==END.p-1||TOP.p==END.p||TOP.p==NULL||END.p==NULL)//END==(TOP-1)
		return;
	int flag=*TOP.p;
	pointer head=TOP,tail=END;	
	while(head.p!=tail.p)
	{
		while((tail-1).p!=NULL&&head.p!=tail.p&&*tail.p>=flag)
			tail--;
		if(tail.p!=NULL)
		{
			cout<<"instead "<<*head.p<<"with "<<*tail.p<<"and flag is "<<flag<<endl;
			*head.p=*tail.p;
		}
		while((head+1).p!=NULL&&head.p!=tail.p&&*head.p<=flag)
			head++;
		if(head.p!=NULL)
		{
			cout<<"instead "<<*tail.p<<"with "<<*head.p<<"and flag is"<<flag<<endl;
			*tail.p=*head.p;
		}
	}
	*tail.p=flag;
	quicksort(TOP,tail-1);
	quicksort(tail+1,END);
}//一个复杂的数据结构必须足以提供足够方便的访问方式，无疑，这里涉及的比较失败，尤其是边界条件让我感到超出控制！