#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

#include "tstack.h"

class Parser {
private:
	
public:

	bool isOperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/';
	}

	int priority(char op) {
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
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

	std::string infixToPostfix(std::string& expr) {
		std::stringstream output;
		TStack<char> operators;
		for (char c : expr) {
			if (isdigit(c) || c=='.' || c==',') {
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
				operators.pop(); 
			}
		}
		while (!(operators.empty())) {
			output << ' ' << operators.top();
			operators.pop();
		}
		return output.str();
	}

	int evaluatePostfix(std::string& expr) {
		TStack<float> values_i;
		std::stringstream ss(expr);
		std::string token;
		while (ss >> token) {
			//values_i.print();
			if (isdigit(token[0])) {
				values_i.push(stof(token));
			}
			else if (isOperator(token[0])) {
				float b = values_i.top();
				values_i.pop();
				float a = values_i.top();
				values_i.pop();
				float result = applyOp(a, b, token[0]);
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
		outp = '(' + outp + ')';
		return outp;
	}

	std::string removeSpaces(const std::string& input) {
		std::string outp;
		for (char ch : input) {
			if (ch != ' ') {
				outp += ch;
			}
		}
		return outp;
	}

	std::string unarMinus(std::string& str) {
		int j=3;
		for (int i = 0; i < str.length()-1; i++) {
			if (str[i] == '(' && str[i + 1] == '-') {
				str.insert(i + 1, 1, '(');
				str.insert(i + 2, 1, '0');
				while (isdigit(str[i + j])) {
					j++;
				}
				str.insert(i + j, 1, ')');
				//std::cout << j << std::endl;
			}
		}
		return str;
	}
	int work(std::string expr) {
		expr = removeSpaces(expr);
		expr = closeBrackets(expr);
		expr = unarMinus(expr);
		//std::cout << expr << std::endl;
		std::string postfix = infixToPostfix(expr);
		//std::cout << "Postfix Expression: " << postfix << std::endl;
		float result = evaluatePostfix(postfix); 
		return result;
	}
};