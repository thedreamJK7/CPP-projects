#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <stdlib.h>

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
	
	private:
		std::map<std::string, double> _data;

		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange &operator = (BitcoinExchange const &);
};

#endif