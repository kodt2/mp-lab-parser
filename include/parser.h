#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

#include "tstack.h"

class Parser {
private:
	
public:


	// Функция для проверки, является ли символ оператором
	bool isOperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/';
	}

	// Функция для определения приоритета оператора
	int priority(char op) {
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		return 0;
	}

	// Функция для выполнения арифметической операции
	int applyOp(int a, int b, char op) {
		switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		}
		return 0;
	}

	// Функция для преобразования инфиксного выражения в постфиксное
	std::string infixToPostfix(std::string& expr) {
		std::stringstream output;
		TStack<char> operators;
		bool op = operators.empty();
		for (char c : expr) {
			if (isdigit(c)) {
				output << c;
			}
			else if (isOperator(c)) {
				while (!(operators.empty()) && priority(operators.top()) >= priority(c)) {
					output << ' ' << operators.top();
					operators.pop();
				}
				output << ' ';
				operators.push(c);
			}
			else if (c == '(') {
				operators.push(c);
			}
			else if (c == ')') {
				while (!(operators.empty()) && operators.top() != '(') {
					output << ' ' << operators.top();
					operators.pop();
				}
				operators.pop(); // Remove the '('
			}
		}
		while (!(operators.empty())) {
			output << ' ' << operators.top();
			operators.pop();
		}
		return output.str();
	}

	// Функция для вычисления значения постфиксного выражения
	int evaluatePostfix(std::string& expr) {
		TStack<int> values;
		std::stringstream ss(expr);
		std::string token;
		while (ss >> token) {
			if (isdigit(token[0])) {
				values.push(stoi(token));
			}
			else if (isOperator(token[0])) {
				int b = values.top(); values.pop();
				int a = values.top(); values.pop();
				int result = applyOp(a, b, token[0]);
				values.push(result);
			}
		}
		return values.top();
	}

	void work(std::string expr) {
		std::string postfix = infixToPostfix(expr);
		std::cout << "Postfix Expression: " << postfix << std::endl;
		int result = evaluatePostfix(postfix);
		std::cout << "Result: " << result << std::endl;
	}

};