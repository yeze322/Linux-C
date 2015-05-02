#include"HashSave.h"

node* CreateNode()
{
	node *p=new node;
	p->next=NULL;
	p->num=0;
	return p;
}

Info* CreateInfo()
{
	Info* p=new Info;
	p->head=CreateNode();
	p->tail=p->head;
	p->num=0;
	p->words=0;
	return p;
}


void AddWord(Info *L,char *s)
{
	node *add=CreateNode();
	add->num++;
	strcpy(add->word,s);
	L->tail->next=add;
	L->words++;
	L->tail=add;
}

bool IfExsist(Info *L,char *s)//搜索是否存在
{
	node *search;
	for(search=L->head->next;search!=NULL;search=search->next)
	{
		if(strcmp(search->word,s)==0)//如果相等！
		{
			search->num++;
			L->num++;
			return true;
		}
	}
	AddWord(L,s);
	return false;
}


void PrintResult(Info *L,FILE *write,int i)
{
	fprintf(write,"Alpha [%c] has %d words.\r\nAnd their number is %d in totoal.\r\nThose words are:\r\n",i+'A',L->words,L->num);
	node *read=L->head->next;
	while(read)
	{
		fprintf(write,"[%d]  %s\r\n",read->num,read->word);
		read=read->next;
	}
	return;
}

void PrintHash(Info **L,FILE *write)
{
	fprintf(write,"ALPHA    WORDS    TOTAL    MAJORITY\r\n");
	for(int i=0;i<26;i++)
	{
		if(L[i]->num==0)
			continue;
		fprintf(write,"%5c    %5d    %5d    %s(%d)\r\n",\
		'A'+i,L[i]->words,L[i]->num,L[i]->head->next->word,L[i]->head->next->num);
	}
	return;
}


int cmpInc(const void *left,const void *right)
{
	node* *p=(node **)left;
	node* *q=(node **)right;
	if((*p)->num<(*q)->num)
		return 1;
	else
		return (*p)->num==(*q)->num?0:-1;
}


void WordQsort(Info *L)
{
	int size=L->words;
	if(size==0)
		return;
	assert(size!=0);
	node* *chain=new node* [size];
	node *visit=L->head->next;
	int i=0;
	while(visit)
	{
		chain[i++]=visit;
		visit=visit->next;
	}
	qsort((node *)(chain),size,sizeof(node*),cmpInc);

	visit=L->head;
	for(int i=0;i<size;i++)
	{
		visit->next=chain[i];
		visit=visit->next;
	}
	visit->next=NULL;
	L->tail=chain[size-1];
	delete(chain);
	chain=NULL;
	return;
}