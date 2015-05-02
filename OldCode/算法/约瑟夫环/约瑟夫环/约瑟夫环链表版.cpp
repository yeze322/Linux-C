#include<stdio.h>
#define TOTAL 100
#define COUNT 5
struct node
{
	int num;
	node* next;
}*head;
node* createman()
{
	node* p=new node;
	p->next=NULL;
	return p;
}
node* sitaround()
{
	head=createman();
	node* father=head;
	father->num=1;
	for(int i=2;i<=TOTAL;i++)
	{
		father->next=createman();
		father->next->num=i;
		father=father->next;
	}
	father->next=head;
	return head;
}
void outman(node* father)
{
	node* p=father->next->next;
	delete(father->next);
	father->next=p;
}

int main()
{
	head=sitaround();
	node* surviver=head;
	while(surviver->next!=surviver)//就剩一个人，自己的下一个指向自己
	{
		for(int i=1;i<COUNT-1;i++)//surviver初始值数1,所以从1开始；因为outman函数直接删掉下一个人，所以不能让count-1执行
			surviver=surviver->next;
		outman(surviver);//数到COUNT的人不出声了直接拍死
		surviver=surviver->next;//阵亡的人后面的人开始数数
	}
	printf("surviver is : No.%d",surviver->num);
	return 0;
}