#include <iostream>


int main()
{
	std::string mozg = "HI THIS IS BRAIN";
	std::string *stringPTR = &mozg;
	std::string &stringREF = mozg;
	std::cout << &mozg << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << mozg << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return 0;
}	