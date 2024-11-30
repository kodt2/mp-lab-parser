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
	float applyOp(float a, float b, char op) {
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
		TStack<int> values_i;
		TStack<float> values_f;
		std::stringstream ss(expr);
		std::string token;
		while (ss >> token) {
			if (isdigit(token[0])) {
				values_i.push(stoi(token));
			}
			else if (isOperator(token[0])) {
				int b = values_i.top(); values_i.pop();
				int a = values_i.top(); values_i.pop();
				int result = applyOp(a, b, token[0]);
				values_i.push(result);
			}
		}
		return values_i.top();
	}

	std::string closeBrackets(std::string& str) {
		std::string outp;
		int cOpen=0, cClose =0;
		for (char c : str) {
			if (c == '(') {
				cOpen++;
			}
			if (c == ')') {
				cClose++;
			}
		}
		if (cOpen > cClose) {
			outp = str;
			for (int i = 0; i < cOpen - cClose; i++) {
				outp = outp + ')';
			}
		}
		if (cClose > cOpen) {
			for (int i = 0; i < cClose - cOpen; i++) {
				outp = outp + '(';
			}
			outp = outp + str;
		}
		return outp;
	}

	void work(std::string expr) {
		expr = closeBrackets(expr);
		std::cout << expr << std::endl;
		std::string postfix = infixToPostfix(expr);
		std::cout << "Postfix Expression: " << postfix << std::endl;
		int result = evaluatePostfix(postfix);
		std::cout << "Result: " << result << std::endl;
	}

};