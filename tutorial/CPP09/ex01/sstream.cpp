#include <iostream>
#include <string>
#include <sstream> // strings to be treated as input and output streams.

int main(int argc, char const *argv[])
{
	std::string str = "4 5 6 7";
	std::stringstream ss(str);
	int num;
	while (ss >> num) {
		std::cout << num << std::endl;
	}
	std::string str1 = "123";
	std::stringstream ss1(str1);  // buffer
	int num1;
	if (!(ss1 >> num1)) { // converting: reading from the stream
		std::cout << "Hidden error" << std::endl;
	}
	else {
		std::cout << num1 << std::endl;
	}
	return 0;
}
