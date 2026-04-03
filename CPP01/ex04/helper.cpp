#include "main.hpp"

/*
	rdbuf():
	Accessing the underlying buffer.
	Returns:
	The current basic_filebuf buffer.
	This hides both signatures of std::basic_ios::rdbuf().
*/

std::string readFile(const std::string &filename)
{
	std::ifstream		ifs(filename.c_str());
	std::string			str;
	std::ostringstream	ss;

	if (!ifs)
	{
		std::cerr << "Error: Unable to open file `" << filename << "`." << std::endl;
		return (std::string());
	}
	ss << ifs.rdbuf();
	str = ss.str();
	ifs.close();
	return (str);
}

std::string replaceString(const std::string &str, const std::string &s1, 
	const std::string &s2)
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

bool writeFile(const std::string &modifiedContent, const std::string &filename)
{
	std::string fname = std::string(filename) + ".replace";
	std::ofstream outFile(fname.c_str());
	if (!outFile)
		return (std::cout << "Failed to create output file" << std::endl, false);
	outFile << modifiedContent << std::endl;
	outFile.close();
	return (true);
}

void printUsage()
{
    std::cout << "Usage: <filename> <search_string> <replacement_string>" << std::endl;
}
