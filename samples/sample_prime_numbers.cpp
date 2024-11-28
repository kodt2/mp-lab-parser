#include <iostream>
#include "parser.h"
int main() {
	Parser parser;
	std::cout << "input: 3 + 5 * (2 - 8)"<<std::endl;
	parser.work("3 + 5 * (2 - 8)");
	
}