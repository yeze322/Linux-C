#include"sitchart.h"
//重建链表。链表的意义就是离散输入，排序后就成为类似二维数组结构
int cprow(const void *left,const void *right)
{
	node *a=*(node**)left;
	node *b=*(node**)right;
	return a->row-b->row;
}
int cpcol(const void *left,const void *right)
{
	node *a=*(node**)left;
	node *b=*(node**)right;
	return (a->col)-(b->col);
}


void sortrow(nodehead *head)
{
	node *a[20];
	node *visit=head->head->down;
	int i=0;
	while(visit)
	{
		a[i++]=visit;
		visit=visit->down;
	}
	
	qsort(a,head->num,sizeof(node*),cprow);
	visit=head->head;
	for(i=0;i<head->num;i++)
	{
		visit->down=a[i];
		visit=visit->down;
	}

	head->tail=a[head->num-1];
	head->tail->down=NULL;
}

void sortcol(nodehead *head)
{
	node *a[20];
	node *visit=head->head->right;
	int i=0;
	while(visit)
	{
		a[i++]=visit;
		visit=visit->right;
	}
	qsort(a,head->num,sizeof(node*),cpcol);
	visit=head->head;
	for(i=0;i<head->num;i++)
	{
		visit->right=a[i];
		visit=visit->right;
	}

	head->tail=a[head->num-1];
	head->tail->right=NULL;
}
void rebuild(list *L)
{
	for(int i=0;i<N;i++)
	sortrow(L->colhead[i]);
	
	for(int i=0;i<M;i++)
	sortcol(L->rowhead[i]);
}
