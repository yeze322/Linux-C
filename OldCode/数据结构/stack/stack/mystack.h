#define N 100
struct stack{//容量为100的栈
	int data[N];
	int top;
}S;

void Initialize(stack &S)//初始化，栈顶指针不指向任何元素
{
	S.top=-1;
}
bool StackEmpty(stack S)//判断栈是否为空
{
	if(S.top==-1)
		return true;
	else
		return false;
}
bool Push(stack &S,int a)//将int a入栈
//需要修改S，所以要用地址的形式。下同
{
	if(S.top==N-1)
		return false;
	S.data[++S.top]=a;
	return true;
}
bool Pop(stack &s,int &x)//出栈到一个int值
{
	if(s.top<0)
		return false;
	x=s.data[s.top--];
	return true;
}
bool GetTop(stack *s,int *x)//读取栈顶元素
//这个用指针形式写一下，原理是一样的。另外我觉得bool型用着还是不习惯，更喜欢用VOID或者INT
{
	if(s->top==-1)
		return false;
	*x=s->data[s->top];
	return true;
}