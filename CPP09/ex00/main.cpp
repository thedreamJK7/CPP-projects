#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
	}
	BitcoinExchange btc;
	btc.process(argv[1]);
	return (0);
}
