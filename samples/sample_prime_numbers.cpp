#include <iostream>
#include "parser.h"
int main(int argc, char* argv[]) {
	Parser parser;
	if (argc>1) {
		std::string str = std::string(argv[1]);
		std::cout << str << std::endl;
		parser.work(str);
	}
	else {
		std::string str;
		str = "3 + 5 * (2 - 8)(";
		std::cout << str << std::endl;
		parser.work(str);
	}
}