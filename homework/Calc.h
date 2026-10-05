#pragma once
#include <iostream>
#include "Struct.h"

using namespace std;

class Calc {
	string expression;

	int isoperation(char c) const;
	int getResult() const;
	int calculate(int a, int b, char oper) const;

public:
	Calc(const string& exp) : expression(exp) {}
	

	
};

int Calc::isoperation(char oper) const
{
	switch (oper)
	{
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^':          return 3;
	default:           return 0;
	}
}

int Calc::calculate(int a, int b, char oper) const
{
	switch (oper)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default:
		break;
	}
}


int Calc::getResult() const {
	Stack<int, 10> numbers;
	Stack<char, 10> operators;

	int i = 0;
	while (expression[i] != '\0') {
		if (isdigit(expression[i])) {
			numbers.push(expression[i] - '0');

		}

		else if (isoperation(expression[i])) {
			operators.push(expression[i]);
		}

		else if (expression[i] == ')') {
			int num2 = numbers.peek();
			numbers.pop();
			int num1 = numbers.peek();
			numbers.pop();
			char op = operators.peek();
			operators.pop();
			int result;
			switch (op) {
			case '+':
				result = num1 + num2;
				break;
			case '-':
				result = num1 - num2;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
				result = num1 / num2;
				break;
			default:
				cout << "Invalid operator: " << op << endl;
				return 0;
			}	
			numbers.push(result);
		}
	}
	return 0;
}





