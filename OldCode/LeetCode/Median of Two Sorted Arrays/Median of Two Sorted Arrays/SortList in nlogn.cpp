#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if(head == NULL||head -> next == NULL)
			return head;
		ListNode *fast,*slow;
		fast = slow = head;
		while(fast->next!=NULL && fast->next->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow ->next;
		}
		fast = slow->next;
		slow -> next = NULL;// cut list
		slow = fast;
		ListNode *head1 = sortList(slow);
		ListNode *head2 = sortList(head);
		return mergelist(head1,head2);
	}

	ListNode* mergelist(ListNode *left,ListNode *right)
	{
		ListNode head = ListNode(0);
		ListNode *p=&head;
		while(left!=NULL&&right !=NULL)
		{
			if(left->val<right->val)
			{
				p->next = left;
				left = left->next;
			}else{
				p->next = right;
				right = right ->next;
			}
			p=p->next;
		}
		if(left == NULL)
			p->next = right;
		else
			p->next = left;
		return head.next;
	}
};