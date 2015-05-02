#include "StdAfx.h"
#include "TList.h"
#include<iostream>
using namespace std;


TList::TList(void)
{
}


TList::~TList(void)
{
}

bool TList::hasCircle(CList myList){
	if(myList == NULL || myList->next == NULL){
		return false;
	}

	CNode *slow = myList->next;
	CNode *fast = slow->next;

	if(slow->next == NULL){
		return false;
	}

	while(fast != NULL && fast != slow){
		slow = slow->next;
		fast = slow->next;
	}

	if(fast == slow){
		return true;
	}

	return false;
}

CNode* TList::getLastK(CList myList, int k){
	if(myList == NULL || myList->next == NULL || k < 0){
		return NULL;
	}

	//TODO: add your code here
	
}

CList TList::mergeList(CList fList, CList nList){
	if(fList == NULL || nList == NULL){
		return NULL;
	}
	
	//TODO: Add your code here
	
}

void TList::inverseList(CList myList){
	if(myList == NULL){
		return;
	}

	// recusive method
	if( myList != NULL){
		inverseList(myList->next);
	}

	cout << myList->data << "\t";
	
}

