#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
	/*	stack<char *> save;
	save.push(NULL);
	char *p=save.top();
	return 0;*/
	ListNode fakehead=ListNode(0);//=ListNode(0);
	fakehead.val=1;
	ListNode fakehead2=ListNode(0);//=ListNode(0);
	fakehead2.val=2;
	fakehead.next=&fakehead2;
	fakehead2.next=NULL;
	return 0;

}
