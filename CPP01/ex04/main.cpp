#include "main.hpp"

int main(int argc, char *argv[])
{
	std::string	str;

	if (argc != 4)
		return (printUsage(), 1);

	std::string filename = argv[1];
    std::string searchString = argv[2];
    std::string replaceStringArg = argv[3];

	if (filename.empty() || searchString.empty() || replaceStringArg.empty())
        return (printUsage(), 1);

	std::string content = readFile(filename);
    if (content.empty())
	{
        return (1);
	}
	
	std::string modifiedContent = replaceString(content, searchString, replaceStringArg);
    if (!writeFile(modifiedContent, filename))
	{
        return 1;
	}
	return (0);
}
