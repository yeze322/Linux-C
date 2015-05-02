#ifndef _LIST_
#define _LIST_
#include<iostream>
#include<assert.h>
using namespace std;
typedef struct LinkedlistNode //链表节点
{
	int data;
	LinkedlistNode* next;
}node;

struct LinkInfo //用来记录链表头结点、最后一个节点、元素个数
{
	int listlen;
	LinkedlistNode *head,*tail;
};

node* NewNode(void);//创建一个链表节点
LinkInfo* CreateLinkInfo();//创建一个空的链表信息
void AddNodeToInfo(LinkInfo*,int);//给LinkInfo的后面增加一个节点
LinkInfo* CreateInfoFromArray(int [],int);//创建一个链表，它的值从array中取

node* CreateSonNode(node *father,int num);//创建father的子节点
void FreeNode(node *start);//free节点start所指的节点
LinkInfo* InitListInfo(LinkInfo *listHead);//创建一个空的的链表,返回它的信息
bool DestroyList(node *L);//销毁整个表
bool ClearList(node *LHead);//把L置为空表，释放原节点空间
bool InsertHead(node *head,node *add);//头插法
bool DeleteFirst(node *head);//删除头结点后第一个节点
bool Append(LinkInfo *LInfo,node *s);//把s所指的一串节点加到L后面，并更新L的尾指针
bool InsertBefore(LinkInfo *L,node *p,node *S);//在链表L的p节点前加入节点S
bool InsertAfter(LinkInfo *L,node *p,node *S);//在链表L的p节点后加入节点S
node* PrirorPos(node *head,node *p);//返回p的前驱节点的位
node* Search(node *head,int value);//搜索节点


//1-单链表反转 中间变量方式
void ReverseList(LinkInfo *head);
//2-倒数第K个
node* lastK(LinkInfo L,int k);
//3-中间节点
node* FinMid(LinkInfo L);
//4-删除无头结点
void DelNoHead(node *p);
//5-两个有序链表合并
LinkInfo* MergeList(LinkInfo *M,LinkInfo *N);
//6-链表是否有环
node* IfCircle(node *);
//7+8-两个链表的交点？求交点
node* Intersection1(node*,node*);
node* Intersection2(node*,node*);
//9-单链表排序,Qsort
void LinkSortQ(LinkInfo*,bool);
//10-删除重复元素
void DelRepeated(LinkInfo*);
//11-链表拆分，奇数一个偶数一个
void SplitList(LinkInfo*,LinkInfo*,LinkInfo*);
//12-大整数加法
LinkInfo* BigNumAdd(int a,int b);
char* BigNum(char*,char*);
#endif // !_LIST_