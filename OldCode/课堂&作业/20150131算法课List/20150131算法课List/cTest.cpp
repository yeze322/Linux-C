// cTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sort.h"
#include "Search.h"
#include <stdio.h>
#include <iostream>
#include "List.h"
#include "SStack.h"
#include "Arithmetic.h"
#include<vector>
using namespace std;
#include "ArrayCommon.h"
#include"Convar.h"
#include"TList.h"


int main(int argc, _TCHAR* argv[])
{
	//1======================================

	//Binary Search
	//int data[]={1,5,3,2,4,6};
	//int dataLen = sizeof(data) / sizeof(*data);
	//int val = 4;
	//Search mySearch;
	//int id = mySearch.binarySearch(data, dataLen, val);
	////int id = mySearch.binarySearchW(data, dataLen, val);
	//if(id != -1){
	//	std::cout << val << " is "<< id+ 1<< "th data found!" << std::endl;
	//}else{
	//	std::cout << "not found" << std::endl;
	//}

	//2====================================

	////find second element
	//int data[7] ={1,2,3,4,5,6,9};
	//int len = sizeof(data)/sizeof(int);
	//Search mySearch;
	//int secondVal = mySearch.find2ndData(data, len);
	//if( secondVal == ERROR){
	//	std::cout << "ERROR" <<std::endl;
	//}
	//else{
	//	std::cout<< "2rd value in data array is " << secondVal << std::endl;
	//}

	//3====================================

	//// find max val and min val
	//int data[7] ={1,2,3,4,5,6,9};
	//int len = sizeof(data) / sizeof(int);
	//Search mySearch;
	//int max, min;
	//int result = mySearch.findMaxMinData(data, len, max, min);
	//if(result == ERROR){
	//	cout << "ERROR" << endl;
	//}
	//else{
	//	cout << "max value: " << max << " min value: " << min << endl;
	//}

	//4=====================================
	//// find max val and min val
	//int data[7] ={1,2,3,4,5,6,9};
	//int len = sizeof(data) / sizeof(int);
	//Search mySearch;
	//int max, min;
	//int result = mySearch.findMaxMinData(data,len,max,min);
	//if(result == ERROR){
	//	cout << "ERROR" << endl;
	//}
	//else{
	//	cout << "max value: " << max << " min value: " << min << endl;
	//}

	//5=====================================

	//// find the given element in a circle array
	//int cData[8] = {7,8,9,1,2,3,4,5};
	//int cLen = 8;
	//int val = 5;
	//Search mySearch;
	//int result = mySearch.binarySearchCArray(cData,cLen,val);
	//if(result == ERROR){
	//	std::cout << val << " is not in cArray." << endl;
	//}
	//else{
	//	std::cout << val << " is " << result << "th element in cArray." << endl;
	//}

	//6=====================================

	// Hash examples
	// produce data randomly
	//ArrayCommon myArrayCommon;
	//int len = 10;
	//int low = 0;
	//int high = MAX_SCORE;
	//int *data = new int[len];
	//
	//myArrayCommon.getRandNumArray(data, len, low, high);
	//myArrayCommon.printArray(data, len);

	////find score
	//CHash myHash;
	//int score = 20;
	//int result = myHash.getStuNum(data, len, score);
	//if( result == ERROR){
	//	cout << "ERROR" << endl;
	//}
	//else{
	//	cout << score << " in data appears " << result << " times" << endl;
	//}

	//7====================================================

	//find the first char in str
	/*CHash myHash;
	char str[] ={"hhello,wangdao"};
	char result = myHash.getFirstChar(str);
	cout << "The first char in \"" << str << "\" is: " << result << endl;*/

	//8=====================================
	//int data[]={1,5,3,2,4,6};
	//int dataLen = sizeof(data)/sizeof(*data);

	////before sorting
	//std::cout<<"Before sorting:"<<std::endl;
	//ArrayCommon::printArray(data, dataLen);

	//Sort mySort;

	//mySort.mergeSort(data, dataLen);

	//quick sort
	/*mySort.quickSort(data, dataLen);*/

	////heap sort
	//mySort.heapSort(data, dataLen);
	
	//shell sort
	/*mySort.shellSort(data, dataLen);*/

	//after sorting
	/*std::cout<<"After sorting:" <<std::endl;
	ArrayCommon::printArray(data, dataLen);*/

	//9======================================
	
	// sort by zero
	/*int data[]={2,-1,0,3,-2,0};
	int len = sizeof(data)/sizeof(int);
	Sort mySort;
	int result;

	ArrayCommon myArrayComm;
	cout << " before sortting:" << endl;
	myArrayComm.printArray(data, len);

	result = mySort.sortByZero(data, len);
	if(result == ERROR){
		cout << " ERROR" << endl;
	}
	else{
		cout << " after sortting:" << endl;
		myArrayComm.printArray(data, len);
	}*/

	//10=========================================

	//// sort by zero
	//int data[]={2,-1,0,3,-2,0};
	//int len = sizeof(data)/sizeof(int);
	//Sort mySort;
	//int result;

	//ArrayCommon myArrayComm;
	//cout << " before sortting:" << endl;
	//myArrayComm.printArray(data, len);

	//// three flags
	//result = mySort.sortThreeFlag(data, len);
	//if(result == ERROR){
	//	cout << "ERROR" << endl;
	//}
	//else{
	//	cout << " after sortting:" << endl;
	//	myArrayComm.printArray(data, len);
	//}

	//11=======================================

	//// search - TOPK
	//int data[7] ={1,2,3,4,5,6,9};
	//int len = sizeof(data)/sizeof(int);
	//Search mySearch;
	//
	//int k = 3;
	//int *result = mySearch.getTOPK(data, len, k);
	//cout << " TOP " << k << " elements are:" << endl;
	//ArrayCommon arrayCommon;
	//arrayCommon.printArray(result, k);
	//delete[] result;

	//==========================================
	
	////链表数据结构==========================
	//int data[]={1,5,3,2,4,6};
	//int dataLen = sizeof(data)/sizeof(*data);
	//List myList;
	//CList cList = NULL;

	////初始化List
	//myList.initList(&cList);

	////往链表中插入值
	//for(int i=0; i<6; i++){
	//	myList.insertNodeLast(cList,data[i]);
	//}

	////输出链表
	//std::cout << " traverse List:" << endl;
	//myList.traverseList(cList);

	//// 逆序输出
	//std::cout << " traverse inverse List:" << endl;
	//myList.outputInverseList(cList);

	//myList.bubbleSortList(cList);

	//myList.traverseList(cList);

	////链表的长度
	//int len = myList.getLength(cList);
	//std::cout<<std::endl<<"List's Size: "<<len<<std::endl;

	////查找
	//int value = 1;
	//int valueIndex = myList.getNodeIndex(cList,value);
	//std::cout<<std::endl<<value<<": index is "<<valueIndex<<std::endl;

	////删除节点
	//int deleteVal = 1;
	//myList.deleteNodeId(cList,deleteVal);
	//std::cout<<std::endl<<deleteVal<< "th node is deleted."<< "The value list after deleting:"<<std::endl;
	//myList.traverseList(cList);

	// =========================================

	//栈===================
	////入栈
	//SStack mystack;
	//for( int i = 0; i < 6; i++){
	//	mystack.push( data[i]);
	//}

	////遍历栈
	//mystack.traverse();

	////出栈
	//int topelememt =mystack.pop();
	//std::cout<<std::endl<< " after pop(), the stack as follows:"<<std::endl;
	////mystack.traverse();

	// 链表的例子========================================

	// 1 判断链表是否有环 ===============================
	//int data[]={1,5,3,2,4,6};
	//int dataLen = sizeof(data)/sizeof(*data);
	//List myList;
	//CList cList = NULL;

	////初始化List
	//myList.initList(&cList);

	////往链表中插入值
	//for(int i = 0; i < dataLen; i ++){
	//	myList.insertNodeLast(cList, data[i]);
	//}

	////输出链表
	//std::cout << " traverse List:" << endl;
	//myList.traverseList(cList);

	//TList tList;
	//bool result = tList.hasCircle(cList);
	//if(result){
	//	cout << "List has a circle. " << endl;
	//}
	//else{
	//	cout << "List has not a circle. " << endl;
	//}
	
	// 2 查找链表倒数第k个节点===========================
	//int data[]={1,5,3,2,4,6};
	//int dataLen = sizeof(data)/sizeof(*data);
	//List myList;
	//CList cList = NULL;

	////初始化List
	//myList.initList(&cList);

	////往链表中插入值
	//for(int i=0; i<dataLen; i++){
	//	myList.insertNodeLast(cList,data[i]);
	//}

	////输出链表
	//std::cout << " traverse List:" << endl;
	//myList.traverseList(cList);

	//TList tList;
	//int k = 6;
	//CNode* result = tList.getLastK(cList, k);
	//if(result == NULL){
	//	cout << "List has not last " << k << "th node or ERROR. " << endl;
	//}
	//else{
	//	cout << "List has last " << k << "th node: " << result->data << endl;
	//}

	// 3 合并俩个有序的单链表===========================
	//int data[]={1,5,7,8,11,16};
	//int dataLen = sizeof(data)/sizeof(*data);
	//List myList;
	//CList aList = NULL;

	////初始化List
	//myList.initList(&aList);

	////往链表中插入值
	//for(int i=0; i<dataLen; i++){
	//	myList.insertNodeLast(aList,data[i]);
	//}

	////输出链表
	//std::cout << " List a:" << endl;
	//myList.traverseList(aList);

	//// list b
	//int dataB[]={2,4,7,8,21,36};
	//int dataBLen = sizeof(data)/sizeof(*dataB);
	//CList bList = NULL;

	////初始化List
	//myList.initList(&bList);

	////往链表中插入值
	//for(int i = 0; i < dataBLen; i++){
	//	myList.insertNodeLast(bList, dataB[i]);
	//}

	////输出链表
	//std::cout << " List b:" << endl;
	//myList.traverseList(bList);

	//TList tList;
	//CList mList = tList.mergeList(aList, bList);
	//if(mList == NULL){
	//	cout << "ERROR: input para error. " << endl;
	//}
	//else{
	//	cout << "List a and List b are merge into List: " << endl;
	//	myList.traverseList(mList);
	//}
	
	// 4 inverse list===================================

	int data[]={1,5,3,2,4,6};
	int dataLen = sizeof(data)/sizeof(*data);
	List myList;
	CList cList = NULL;

	//初始化List
	myList.initList(&cList);

	//往链表中插入值
	for(int i=0; i<dataLen; i++){
		myList.insertNodeLast(cList,data[i]);
	}

	//输出链表
	std::cout << " traverse List:" << endl;
	myList.traverseList(cList);

	TList tList;
	tList.inverseList(cList->next);
	cout << endl;

	// ==================================================	

	//栈的一个实际应用 ---- 表达式计算
	/*string expression ="1+2*3";
	string sub = expression.substr(2,1);
	std::cout<<sub;*/

	/*stack<int> stExample;
	stExample.push(1);
	stExample.push(2);

	cout<<"top: "<<stExample.top()<<endl;


	vector<int> vTest;
	vTest.push_back(1);
	vTest.push_back(2);
	vTest.push_back(3);

	cout<<"vector: "<<vTest[1]<<endl;*/

	//Arithmetic myArithmetic;
	//myArithmetic.runCalculateOperation();

	int iCin;
	cout<<"input any character to exit." << endl; 
	scanf("%d", &iCin);
	return 0;
}