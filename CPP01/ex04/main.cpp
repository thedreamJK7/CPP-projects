#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
	rdbuf():
	Accessing the underlying buffer.
	Returns:
	The current basic_filebuf buffer.
	This hides both signatures of std::basic_ios::rdbuf().
*/

std::string readFile(std::string filename)
{
	std::ifstream		ifs(filename.c_str());
	std::string			str;
	std::ostringstream	ss;

	if (!ifs)
	{
		std::cout << "There is no such file exist" << std::endl;
		return (std::string());
	}
	ss << ifs.rdbuf();
	str = ss.str();
	ifs.close();
	return (str);
}

std::string replaceString(std::string str, std::string s1, std::string s2)
{
	size_t		pos;
	std::string	result;

	pos = 0;
	while (pos < str.length())
	{
		size_t found = str.find(s1, pos);
		if (found != pos)
		{
			result += str[pos];
			pos++;
		}
		else
		{
			result += s2;
			pos += s1.length();
		}
	}
	return (result);
}

bool writeFile(std::string str, std::string filename, std::string s1, std::string s2)
{
	std::string	result;

	result = replaceString(str, s1, s2);
	std::string fname = std::string(filename) + ".replace";
	std::ofstream outFile(fname.c_str());
	if (!outFile)
	{
		std::cout << "Failed to create output file" << std::endl;
		return (1);
	}
	outFile << result << std::endl;
	outFile.close();
	return (0);
}

int main(int argc, char *argv[])
{
	std::string	str;

	if (argc != 4 || std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << "Instructions: <filename> s1 s2" << std::endl;
		return (1);
	}
	str = readFile(argv[1]);
	if (str.empty())
		return (1);
	if (!writeFile(str, argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}
