/*第22题 n名学生的成绩已在主函数中放入一个带头节点的链表结构中，
h指向链表的头节点。请编写函数fun，
它的功能是：找出学生的最高分，由函数值返回*/
#include<iostream>
struct student{
	int score;
	student *next;
};

int fun(student *head)
{
	int high;
	student *p=head;
	high=p->score;
	while(p!=NULL)
	{
		if(p->score>high)
			high=p->score;
		p=p->next;
	}
	return high;
}

int main()
{
	student stu1,stu2,stu3,stu4;
	stu1.score=12;
	stu2.score=8979;
	stu3.score=99;
	stu4.score=77;

	stu1.next=&stu2;
	stu2.next=&stu3;
	stu3.next=&stu4;
	stu4.next=NULL;//空指针！别忘了！！！！

	int high=fun(&stu1);
	std::cout<<high;
	getchar();
}