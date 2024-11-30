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
		str = "-300 + 5 * ((-2) - 8*2)(";
		std::cout << str << std::endl;
		float res = parser.work(str);
		float res1 = -300 + 5 * ((-2) - 8 * 2);
		std::cout << res << std::endl;
		//std::cout << res1 << std::endl;
	}
}