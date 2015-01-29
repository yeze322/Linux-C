#include"sitchart.h"
#define M 8
#define N 9
struct node
{
	int row;
	int col;
	char name[20];
	struct node *right;
	struct node *down;
};//个人信息节点。包含名字、行数、列数、右边人、后边人

struct nodehead
{
	int num;
	struct node *head;
	struct node *tail;
};//单行、单列的头结点，用于记录行人数或列人数、以及尾节点

struct list
{
	nodehead *rowhead[M];
	nodehead *colhead[N];
	//int rownum;
	//int colnum;
	int stunum;
};//list结构，代表整个网的头结点，包括一行头结点、一列头结点
//包含数据——行数、列数、人数
