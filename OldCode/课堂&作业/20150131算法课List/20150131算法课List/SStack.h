#pragma once
class SStack
{
public:
	SStack(void);
	~SStack(void);

	int getTop();
	int push(int value);
	int pop(); // delete the element of top
	int getLength();
	int traverse();
	bool isFull();
	bool isEmpty();


private:
	int * data;
	int * base;
	int * top;
	int * bottom;
	int MAX_SIZE;
};

