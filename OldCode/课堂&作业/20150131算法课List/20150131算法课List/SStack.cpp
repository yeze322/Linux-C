#include "StdAfx.h"
#include "SStack.h"
#include "Convar.h"
#include <iostream>

SStack::SStack(void)
{
	MAX_SIZE = 1001;
	data = new int[MAX_SIZE];
	top = data;
	bottom = data;

	//std::cout<< " run construction fuction"<< std::endl;
}

  
SStack::~SStack(void)
{
}

int SStack::push(int element){
	if( isFull()){
		std::cout<< " Error: the stack is full."<<std::endl;
		return ERROR;
	}
	
	*top = element;
	top ++;

	return OK;
}

int SStack::pop(){
	if( isEmpty()){
		return ERROR;
	}

	top --;
	return *top;
}

int SStack::getTop(){
	if(isEmpty()){
		return ERROR;
	}
	int * tmp = top;
	tmp--;
	return *tmp;
}

bool SStack::isEmpty(){
	return top == bottom;
}

bool SStack::isFull(){
	return top - bottom == MAX_SIZE - 1;
}

int SStack::getLength(){
	return (bottom - top) % MAX_SIZE; 
}

int SStack::traverse(){
	if( isEmpty()){
		return ERROR;
	}

	std::cout<<"traverse the stack as follows:"<<std::endl;

	int * p = top;
	while( p != bottom){
		p --;
		std::cout<< *p<<"\t";
	}

	std::cout<<std::endl;

	return OK;
}