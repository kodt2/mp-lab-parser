#include <iostream>
#include "parser.h"
int main(int argc, char* argv[]) {
	Parser parser;
	if (argc>1) {
		std::string str = std::string(argv[1]);
		//std::cout << str << std::endl;
		parser.work(str);
	}
	else {
		std::string str;
		str = "(2*(8-9))";
		std::cout << str << std::endl;
		float res;
		try {
			res = parser.work(str);
		}
		catch (std::string err) {
			std::cout << err << std::endl;
		}
		
		float res1 = -300 + 5 * ((-2) - 8 * 2);
		std::cout << res << std::endl;
		std::cout << res1 << std::endl;
	}
}