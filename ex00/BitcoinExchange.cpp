/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:12:48 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/07 15:38:35 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_db = std::map<std::string, float>();
std::map<std::string, float> BitcoinExchange::_input = std::map<std::string, float>();
std::ifstream BitcoinExchange::_dbFile = std::ifstream("data.csv");
std::ifstream BitcoinExchange::_infile = std::ifstream();

/**
 * Fills _db std::map with data.csv database. It avoids first line.
*/
void BitcoinExchange::fillDataBase() {
	std::string line;

	while (std::getline(_dbFile, line)) {
		if (line == "date,exchange_rate")
			continue ;
		std::string key = line.substr(0,9);
		float		val = std::atof(line.substr(11,line.size()).c_str());
		_db.insert(std::pair<std::string, float>(key, val));
	}
}

/**
 * Check if the received line contains a valid date at the begining of the line.
*/
bool BitcoinExchange::validDate(std::string line) {
	int year;
	int month;
	int day;

	while (std::getline(_infile, line)) {
		if (line == "date | value")
			continue ;
		year = std::atoi(line.substr(0,3).c_str());
		if (year < 1 || year > 2013)
			return (false);
		month = std::atoi(line.substr(5,6).c_str());
		if (month < 1 || month > 12)
			return (false);
		day = std::atoi(line.substr(8,9).c_str());
		if (day < 1 || day > 31)
			return (false);
	}
	return (true);
}

void BitcoinExchange::convertData(const char *infile_name) {
	fillDataBase();
	_infile.open(infile_name); // Try to pass a wrong file and check behaviour!!!!!

	std::string line;

	while (std::getline(_infile, line)) {

	}

}













/*
	The class is static and it cannot be instantiated.
	(Constructors, destructor and assignation operator are private)
*/
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp) { (void)cp; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cp) { (void)cp; return (*this); }


