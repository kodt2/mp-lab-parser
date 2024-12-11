#include <iostream>
#include "parser.h"
int main() {
	Parser parser;
	std::string str;
	float res;
	while (true) {
		std::cin >> str;
		res = parser.work(str);
		std::cout << " " << res << " " << std::endl;
	}
	return 0;
}
