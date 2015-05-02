#include "StdAfx.h"
#include "Arithmetic.h"
#include<iostream>
#include<math.h>
#include"Convar.h"

using namespace std;

Arithmetic::Arithmetic(void)
{
	
}


Arithmetic::~Arithmetic(void)
{
}

double parseStringToDouble(string);
double operate(double,double,char);
bool isNumber(char);
int getOperatorId(char);


int priorityMatrix[4][4] = {{1,1,0,0},
	{1,1,0,0},
	{1,1,1,1},
	{1,1,1,1}};

double Arithmetic::calculateOperation(string expression){
	if( !isValidExpression()){
		cout<< "Error: Expression is illeagle!"<<endl;
		return DBL_MAX;
	}

	double result = 0;
	int expressionLen = expression.size();
	bool characterFlag = true;
	int numStartId = 0;
	for( int i =0; i < expressionLen; i++){
		char character = expression.at(i);
		int operatorId = getOperatorId(character);
		if(operatorId !=-1){ // the character is an operator
			characterFlag = true;
			if(numStartId <= i-1){
				string numStr = expression.substr(numStartId, i-numStartId);
				double num = parseStringToDouble(numStr);
				cout<< num << " push into stack!"<<endl;
				dataStack.push(num);

			}

			if( operatorStack.size()==0){
				operatorStack.push( character);
			}

			else{
				char topCharacter = operatorStack.top();
				int topOperatorId = getOperatorId(topCharacter);

				if( priorityMatrix[operatorId][topOperatorId] == 1){//the next operator is priori to the top one
					operatorStack.push( character);
				}
				else{
					double nextData = dataStack.top();
					dataStack.pop();

					double previousData = dataStack.top();
					dataStack.pop();

					double resultTmp = operate(previousData, nextData, topCharacter);
					dataStack.push(resultTmp);
					cout<<resultTmp<< " push into stack!!"<<endl;
	
					operatorStack.pop();
					operatorStack.push(character);
				}// end if priorityMatrix
			}// end if operatorStack.size
			numStartId = i+1;
		}

		else if(isNumber(character)){
			if(characterFlag){
				numStartId = i;
			}
			characterFlag = false;
		}

		else{
			cout<<character<< " s illeagle character."<<endl;
			return DBL_MAX;;
		}
	}

	//the last data
	string numStr = expression.substr(numStartId, expressionLen);
	double num = parseStringToDouble(numStr);
	dataStack.push(num);

	while(operatorStack.size() > 0 && dataStack.size()> 0){
		char op = operatorStack.top();
		operatorStack.pop();

		double nextData = dataStack.top();
		dataStack.pop();
		double previousData = dataStack.top();
		dataStack.pop();

		double resultTmp = operate(previousData, nextData, op);
		dataStack.push(resultTmp);
	}

	if(operatorStack.size() == 0 && dataStack.size() ==1){
		result = dataStack.top();
		dataStack.pop();

		return result;
	}

	return DBL_MAX;
}

bool Arithmetic::isValidExpression(){
	return true;
}

double parseStringToDouble(string item){
	double result =0;
	int itemLen = item.size();
	for( int i=0;i<itemLen;i++){
		char character = item.at(i);
		if(isNumber(character)){
			double w= itemLen -i -1;
			int number = character- '0';
			result += pow(10, w)*number;
		}
		else{
			cout<< item<< " is not a number!"<<endl;
			return 0;
		}
	}

	return result;
}

bool isNumber(char character){
	if( character >= '0' && character <= '9'){
		return true;
	}
	return false;
}

int getOperatorId(char op){
	if(op =='+'){
		return 0;
	}

	if( op == '-'){
		return 1;
	}

	if( op == '*'){
		return 2;
	}

	if( op == '/'){
		return 3;
	}

	return -1;
}

double operate(double firstData, double nextData, char op){
	if(op =='+'){
		return firstData + nextData;
	}

	if( op== '-'){
		return firstData - nextData;
	}

	if(op =='*'){
		return firstData * nextData;
	}

	if(op =='/'){
		return firstData / nextData;
	}

	std::cout<< "Error: operator is illeage!"<<endl;
	return 0;
}

int Arithmetic::runCalculateOperation(){
	while(true){
		cout<<" input an expression, just include +-*/ operations, and input ****** exit."<<endl;
		string expression;
		cin >> expression;

		if(expression.compare("******")==0){
			cout<< "exit calculation!"<<endl;
			break;
		}

		double result = calculateOperation(expression);
		if(result != DBL_MAX){
			cout <<expression<< " == " <<result<<endl;
		}
	}
	return OK;
}
