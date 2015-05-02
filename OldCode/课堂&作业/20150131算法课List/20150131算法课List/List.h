#pragma once

struct CNode{
	int data;
	CNode * next;
};

typedef CNode* CList;

class List
{
public:
	List(void);
	~List(void);

	int initList(CList *cList);

	CNode* getNode(CList cList, int nodeIndex);
	int getNodeIndex(CList cList, int value);

	//insert node into list
	int insertNodeFront(CList cList,int value);
	int insertNodeLast(CList cList,int value);

	//get the length of list
	int getLength(CList cList);

	//delete the specific node
	int deleteNodeId(CList cList,int nodeId);
	int deleteNodeValue(CList cList,int value);
	int deleteAll(CList cList);

	//traverse list
	void traverseList(CList cList);
	void outputInverseList(CList cList);

	//sort list
	int selectSortList(CList cList);
	int bubbleSortList(CList cList);

	bool isEmpty(CList cList);





};

