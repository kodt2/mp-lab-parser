#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

#include "tstack.h"

class Parser {
private:
	
public:

#include <iostream>
#include <string>
#include <cctype> // для функции isdigit

	enum State {
			START,
			EXPECT_DIGIT_OR_SIGN,
			EXPECT_DIGIT,
			EXPECT_DECIMAL_OR_OPERATOR,
			EXPECT_OPERATOR,
			OPEN_PARENTHESIS,
			CLOSE_PARENTHESIS,
			ERROR,
			VALID
	};

	bool parse(const std::string& expression) {
			State state = START;
			size_t i = 0;
			while (i < expression.length() && state != ERROR) {
				char ch = expression[i];
				switch (state) {
				case START:
					if (isspace(ch)) {
						state = START;
					}
					else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || isdigit(ch)) {
						state = EXPECT_DIGIT;
					}
					else if (ch == '(') {
						state = OPEN_PARENTHESIS;
					}
					else {
						state = ERROR;
					}
					break;
				case EXPECT_DIGIT_OR_SIGN:
					if (isdigit(ch)) {
						state = EXPECT_DIGIT_OR_SIGN;
					}
					else if (ch == '.') {
						state = EXPECT_DECIMAL_OR_OPERATOR;
					}
					else if (ch == '+' || ch == '-'|| ch=='*'||ch=='/') {
						state = EXPECT_DIGIT;
					}
					else if (ch == '(') {
						state = OPEN_PARENTHESIS;
					}
					else if (ch == ')') {
						state = CLOSE_PARENTHESIS;
					}
					else {
						state = ERROR;
					}
					break;
				case EXPECT_DIGIT:
					if (isdigit(ch)) {
						state = EXPECT_DIGIT_OR_SIGN;
					}
					else if (ch == '.') {
						state = EXPECT_DECIMAL_OR_OPERATOR;
					}
					else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
						state = ERROR;
					}
					else if (ch == '(') {
						state = OPEN_PARENTHESIS;
					}
					else if (ch == ')') {
						state = ERROR;
					}
					else {
						state = ERROR;
					}
					break;
				case EXPECT_DECIMAL_OR_OPERATOR:
					if (isdigit(ch)) {
						state = EXPECT_DECIMAL_OR_OPERATOR;
					}
					else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
						state = EXPECT_DIGIT;
					}
					else if (ch == ')') {
						state = CLOSE_PARENTHESIS;
					}
					else {
						state = ERROR;
					}
					break;
				case EXPECT_OPERATOR:
					if (isspace(ch)) {
						state = EXPECT_OPERATOR;
					}
					else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
						state = EXPECT_DIGIT_OR_SIGN;
					}
					else if (ch == '(') {
						state = OPEN_PARENTHESIS;
					}
					else if (ch == ')') {
						state = CLOSE_PARENTHESIS;
					}
					else {
						state = ERROR;
					}
					break;
				case OPEN_PARENTHESIS:
					if (isdigit(ch)) {
						state = EXPECT_DIGIT_OR_SIGN;
					}
					else if (ch == '+' || ch == '*' || ch == '/') {
						state = ERROR;
					}
					else if (ch == '-') {
						state = EXPECT_DIGIT;
					}
					else if (ch == '(') {
						state = OPEN_PARENTHESIS;
					}
					else if (ch == ')') {
						state = CLOSE_PARENTHESIS;
					}
					else {
						state = ERROR;
					}
					break;
				case CLOSE_PARENTHESIS:
					if (ch == '+' || ch == '*') {
					state = ERROR;
					}
					else if (ch == '/') {
						state = EXPECT_DIGIT_OR_SIGN;
					}
					else if (ch == '-') {
						state = EXPECT_DIGIT;
						}
					else if (isdigit(ch)) {
						state = EXPECT_DIGIT_OR_SIGN;
					}
					else if (ch == ')') {
						state = CLOSE_PARENTHESIS;
					}
					else {
						state = ERROR;
					}
					break;
				default:
					state = ERROR;
					break;
				}
				i++;
		}
		return state == EXPECT_OPERATOR || state == CLOSE_PARENTHESIS || state == VALID|| state==EXPECT_DIGIT_OR_SIGN;
	};

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
		if (cClose == cOpen) {
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

	std::string remove_doub_operators(const std::string& input) {
		std::stringstream ss(input);
		std::string inp = input;
		std::string outp;
		for (int i = 0; i < inp.size()-1; i++) {
			if (inp[i]=='-' && inp[i + 1]=='-') {
				outp += " ";
				inp[i] = ' ';
			}
			if (inp[i] == '+' && inp[i + 1] == '+') {
				outp += " ";
				inp[i] = ' ';
			}
			if (inp[i] == '*' && inp[i + 1] == '*') {
				outp += " ";
				inp[i] = ' ';
			}
			if (inp[i] == '/' && inp[i + 1] == '/') {
				outp += " ";
				inp[i] = ' ';
			}
			if (isOperator(inp[i]) && isOperator(inp[i + 1])) {
				return outp;
			}
			outp += inp[i];
		}
		outp += inp[input.size() - 1];
		
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
		
		//std::cout << expr << std::endl;
		bool a = parse(expr);
		
		if (a) {
			expr = unarMinus(expr);
			//if (expr == "somthing strange piece of shit") {
			//	std::cout << "somthing strange piece of shit" << std::endl;
			//}
			expr = removeSpaces(expr);
			std::string postfix = infixToPostfix(expr);
			//std::cout << "Postfix Expression: " << postfix << std::endl;
			float result = evaluatePostfix(postfix);
			return result;
		}
		else {
			throw "wrong";
		}
	}
};