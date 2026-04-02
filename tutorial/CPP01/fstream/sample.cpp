#include <iostream>
#include <fstream>

int main()
{
	std::ifstream	ifs("numbers");
	unsigned	int	dst = 1;
	unsigned	int	dst2 = 2;
	ifs >> dst >> dst2;

	// reads from the file
	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	// writes to the file
	std::ofstream	ofs("test.out");
	ofs << "i like panies wholle a lot damm" << std::endl;
	ofs.close();
	return (0);
}
