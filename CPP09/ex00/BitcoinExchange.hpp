#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <cstdlib>
#include <cctype> 

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();

		// Methods
		void	process(std::string const &);
		void	printAllData(void);
	
	private:
		std::map<std::string, double> _data;

		void	loadDatabase(const std::string&);
		bool	parseLine(const std::string&, std::string&, double&) const;
		int		maxDaysInMonth(int, int) const;
		bool	validateDateStr(std::string &) const;

		// exceptions
		class fileNotOpened: public std::exception {
			virtual char const *what(void) const throw() {
				return "Error: could not open file.";
			}
		};

		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange &operator = (BitcoinExchange const &);
};

#endif
