#pragma once
#include"List.h"
class TList
{
public:
	TList(void);
	~TList(void);
	
	// tell if a circle exit
	bool hasCircle(CList myList);

	// get the last k node
	CNode* getLastK(CList myList, int k);

	// merge two sorted list
	CList mergeList(CList fList, CList nList);

	void inverseList(CList myList);
};

