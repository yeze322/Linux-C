#include "Linkedlist.h"

node* IfCircle(node * head)//返回值为环的起点，没有环则返回空
{
	if(head==NULL||head->next==NULL)
		return NULL;
	node *slow=head->next;
	node *fast=slow;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			fast=head->next;//参见思路2的分析
			while(fast!=slow)//此时已经确定有环，不需要边界条件
			{
				slow=slow->next;
				fast=fast->next;//此时二者相差N个环的长度，所以fast改成一次走1格
			}
			return fast;
		}
	}
	return NULL;
}

//思路1：链表从头开始访问，节点地址存到额外空间中，每到下一个节点都会查询前面是否有重复的
//		 该方法空间复杂度O(N), 时间复杂度O(N*N),不是一个好方法。
//思路2：两个指针都从头结点开始访问，一个速度为1，一个速度为2。两次相遇求得交点。
//下面是昨天在leetcode上遇见的同一类问题写的分析：
/*Assuming that:

                   S1 = the distance between headA and the intersection (交点)

                     T = the circle's length                  (S1 + T = all nodes)
And:

                   S1 = n*T + delta (int n)
what we know is 'slow''s speed is 1, 'fast''s speed is 2

1-Now we start from headA------

Before slow == fast ,we need to run [S1/T]*T + T = (S1 + T - delta) step.

2-Then we set 'fast' = headA ( and set fast's speed to 1) It means that--now the distance between 'slow' and 'fast' = n*T

3-After another n*T step, slow and fast arrive the intersection!

So, totoaly we move about 2*S1 + T step. Time complexity is O(n)!*/