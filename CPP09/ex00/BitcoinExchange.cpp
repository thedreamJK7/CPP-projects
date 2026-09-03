#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) { 
	(void)rhs;
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

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream					file(filename.c_str());
	size_t							foundComma;
	std::string						line;
	std::pair<std::string, double>	data;		

	if (!file.is_open()) 
		throw BitcoinExchange::fileNotOpened();
	std::getline(file, line);
	while (std::getline(file, line)) {
		foundComma = line.find(',');
		if (foundComma == std::string::npos)
			continue;
		data.first = line.substr(0, foundComma);
		data.second = std::atof(line.substr(foundComma + 1).c_str());
		_data[data.first] = data.second;
	}
}

bool BitcoinExchange::validateDateStr(std::string const &date) {
	if (date[4] != '-' && date[7] != '-') {
		return false;
	}
	int month, year, day;
	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 7).c_str());
	day = atoi(date.substr(8).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1) {
		return false;
	}
	int maxDay;
	switch (month) {
		case 2:
			maxDay = 28;
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				maxDay = 29;
			break;
		case 4: case 6: case 9: case 11: maxDay = 30; break;
		default: maxDay = 31; break;
	}
	return day <= maxDay;
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
		
		if (!validateDateStr(dateStr)) {
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}
		double val = std::atof(valueStr.c_str());
		if (val < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		} else if (val > 1000) {
			std::cerr << "Error: too large number." << std::endl;
			continue;
		}
		
		// - print result
	}
}
