#include "StdAfx.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include "Convar.h"
#include<stack>
#include <iostream>
using namespace std;

List::List(void)
{
}


List::~List(void)
{
}

int List::initList(CList *cList){
	*cList = (CList)malloc(sizeof(CNode));
	if(!cList){
		return ERROR;
	}
	(*cList)->next = NULL;
	return OK;
}

int List::insertNodeFront(CList cList, int value){
	if(cList == NULL){
		std::cout<<"List is NULL!";
		initList(&cList);
	}

	CNode * insertNode =(CNode *)malloc(sizeof(CNode));
	if(insertNode == NULL){
		std::cout<<"cannot malloc a CNode!";
		return ERROR;
	}
	insertNode->data = value;
	insertNode->next = NULL;


	CNode* headNextNode = (cList)->next;
	if( headNextNode == NULL){// have no node in list
		(cList)->next = insertNode;
	}else{ //have some nodes in list
		(cList)->next =insertNode;
		insertNode ->next = headNextNode;
	}
	return OK;
}

int List::insertNodeLast(CList cList, int value){
	if(cList == NULL){
		std::cout<<"List is NULL!";
		return ERROR;
	}
	
	CNode *nodeP=cList;
	while(nodeP->next != NULL){
		nodeP = nodeP->next;
	}

	CNode *insertNode =(CNode*)malloc(sizeof(CNode));
	if(insertNode == NULL){
		std::cout<<" cannot malloc a CNode!";
		return ERROR;
	}

	insertNode->data = value;
	insertNode->next = NULL;

	nodeP->next = insertNode;

	return OK;
}

bool List::isEmpty(CList cList){
	if( cList == NULL){
		return true;
	}else{
		if(cList->next==NULL){
			return true;
		}else{
			return false;
		}
	}
}

int List::getLength(CList cList){
	if(isEmpty(cList)){
		return 0;
	}

	int num = 0;
	CNode *nodeP = cList->next;
	while(nodeP){
		num ++;
		nodeP = nodeP->next;
	}
	return num;

}

void List::traverseList(CList cList){
	if(isEmpty(cList)){
		std::cout<<"List is empty.";
	}

	std::cout<<"List valueList as follows:\n";

	CNode * nodeP = cList->next;
	while(nodeP){
		std::cout<<nodeP->data<<"\t";
		nodeP = nodeP->next;
	}
	std::cout<<std::endl;
}

//´Ó0¿ªÊ¼±àºÅ
int List::deleteNodeId(CList cList, int nodeId){
	if(nodeId <= 0){
		std::cout<< "nodeId is illeagle!";
		return ERROR;
	}
	if(isEmpty(cList)){
		std::cout<<"List is NULL!";
		return ERROR;
	}


	//TODO:Add your code


	return OK;
}

int List::getNodeIndex(CList cList, int value){
	if(isEmpty(cList)){
		std::cout<< "List is Empty!";
		return ERROR;
	}
	CNode *nodeP = cList->next;
	int count = 0;
	while(nodeP){
		if(nodeP->data == value){
			break;
		}
		nodeP = nodeP->next;
		count++;
	}
	return count;
}

int List::selectSortList(CList cList){
	if(isEmpty(cList)){
		std::cout<< "CList is NULL!";
		return ERROR;
	}

	// TODO: Add your code here
	
	
	return OK;
}

int List::bubbleSortList(CList cList){
	if(isEmpty(cList)){
		std::cout<< "CList is NULL!";
		return ERROR;
	}
	CNode * nodeTimes, * nodeP;
	nodeTimes = cList->next;
	int len = getLength(cList);
	int count;
	while(len>0){
		nodeTimes = cList->next;
		len--;
		count = len;
		while(count--){
			nodeP = nodeTimes->next;
			if(nodeTimes->data > nodeP->data){
				int tmp = nodeTimes ->data;
				nodeTimes->data = nodeP->data;
				nodeP->data = tmp;

			}
			nodeTimes = nodeTimes->next;
		}
		
	}
	return OK;
}

void List::outputInverseList(CList cList){
	// TODO: Add your code here

}

