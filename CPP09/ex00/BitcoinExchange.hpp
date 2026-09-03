#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();

		// exceptions
		class fileNotOpened: public std::exception {
			virtual char const *what(void) const throw() {
				return "Error: could not open file.";
			}
		};
		// Methods
		void	process(std::string const &);
		void	printAllData(void);
		bool	validateDateStr(std::string const &);
		bool	validateValStr(std::string const &);
		std::string findCloserDate(std::string const &);
	
	private:
		std::map<std::string, double> _data;

		void	loadDatabase(const std::string& filename);

		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange &operator = (BitcoinExchange const &);
};

#endif

/*
private:
    std::map<std::string, double> _data;

    void   loadDatabase(const std::string& filename);
    bool   parseLine(const std::string& line, std::string& outDate, double& outValue) const;
    bool   isLeapYear(int year) const;
    int    maxDaysInMonth(int year, int month) const;
    double getLowerBoundRate(const std::string& date) const;

    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange& operator=(const BitcoinExchange&);

*/