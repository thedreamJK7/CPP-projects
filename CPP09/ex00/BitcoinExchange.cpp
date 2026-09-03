#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::string	 filename = "data.csv"; 
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		throw BitcoinExchange::fileNotOpened();
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t foundComma = line.find(',');
		if (foundComma == std::string::npos)
			continue;
		std::string date = line.substr(0, foundComma);
		double rate = std::atof(line.substr(foundComma + 1).c_str());
		_data[date] = rate;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) { 
	(void)(rhs);
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void)rhs;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::printAllData(void) {
	std::map<std::string, double>::iterator	it = _data.begin();

	while (it != _data.end()) {
		std::cout << (*it).first << "," << (*it).second << std::endl;
		it++;
	}
}

void BitcoinExchange::process(std::string const &input) {
	std::ifstream file(input.c_str());

	if (!file.is_open()) {
		throw BitcoinExchange::fileNotOpened();
	}
	std::string	line;
	std::getline(file, line);

	while(std::getline(file, line)) {
		size_t	vertical = line.find(" | ");
		if (vertical == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue; 	
		}
		std::string dateStr = line.substr(0, vertical);
		std::string valueStr = line.substr(vertical + 3);
		
		
	}
}