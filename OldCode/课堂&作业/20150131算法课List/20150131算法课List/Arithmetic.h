#pragma once

#include<string>
#include<stack>

using std::string;
using std::stack;

class Arithmetic
{
public:
	Arithmetic(void);
	~Arithmetic(void);

	double calculateOperation( string expression);
	int runCalculateOperation(void);

private:
	bool isValidExpression();
	stack<double> dataStack;
	stack<char> operatorStack;
};

