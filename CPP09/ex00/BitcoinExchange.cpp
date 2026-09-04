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

int		BitcoinExchange::maxDaysInMonth(int year, int month) const {
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
	return maxDay;
}

static bool isDigit(std::string &date) {
	for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;

        if (!isdigit(date[i])) {
            return false;
        }
    }
	return true;
}

bool BitcoinExchange::validateDateStr(std::string &date) const {
	int	month;
	int	year; 
	int	day;
	
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-' || !isDigit(date))
		return false;

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 7).c_str());
	day = atoi(date.substr(8).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;
	return day <= maxDaysInMonth(year, month);
}

bool	BitcoinExchange::parseLine(const std::string& line, 
		std::string& outDate, double& outValue) const {
	size_t		vertical;
	std::string valueStr;

	vertical = line.find(" | ");
	if (vertical == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	outDate = line.substr(0, vertical);
	if (!validateDateStr(outDate)) {
		std::cerr << "Error: bad input => " << outDate << std::endl;
		return false;
	}
	char* endPtr;
    outValue = std::strtod(line.substr(vertical + 3).c_str(), &endPtr);
    if (*endPtr != '\0') {
		std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
	if (outValue < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	} else if (outValue > 1000) {
		std::cerr << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::process(std::string const &input) {
	std::ifstream	file(input.c_str());
	std::string		line;
	std::string		outDate;
	double			outValue;
	std::map<std::string, double>::const_iterator it;

	if (!file.is_open())
		throw BitcoinExchange::fileNotOpened();
	std::getline(file, line);

	while(std::getline(file, line)) {
		if (!parseLine(line, outDate, outValue))
			continue;
		it = _data.find(outDate);
		if (it == _data.end()) {
			it = _data.lower_bound(outDate);
			if (it == _data.begin()) {
				std::cerr << "Error: date too early" << std::endl;
				continue;
			}
			--it;
		}
		if ((*it).first < "2011-01-01") {
			std::cerr << "Error: date too early" << std::endl;
			continue;
		}
		std::cout << outDate << " => " << (*it).second * outValue << std::endl;
	}
}
