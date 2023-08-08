/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:12:48 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/08 14:14:41 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_db = std::map<std::string, float>();
std::map<std::string, float> BitcoinExchange::_input = std::map<std::string, float>();
std::ifstream BitcoinExchange::_dbFile;
std::ifstream BitcoinExchange::_infile;

/**
 * Fills _db std::map with data.csv database. It avoids first line.
*/
void BitcoinExchange::fillDataBase() {
	std::string line;

	while (std::getline(_dbFile, line)) {
		if (line == "date,exchange_rate")
			continue ;
		if (line.size() >= 12) {
			std::string key = line.substr(0,10);
			float		val = std::atof(line.substr(11,line.size()).c_str());
			_db.insert(std::pair<std::string, float>(key, val));
		}
	}
}

/**
 * Check if the received line contains a valid date at the begining of the line.
*/
bool BitcoinExchange::validDate(std::string line) {
	int year;
	int month;
	int day;

	if (line.size() < 9) {
		return (false);
	}
	year = std::atoi(line.substr(0,4).c_str());
	if (year < 1 || year > 2023)
		return (false);
	month = std::atoi(line.substr(5,7).c_str());
	if (month < 1 || month > 12)
		return (false);
	day = std::atoi(line.substr(8,10).c_str());
	if (day < 1
		|| (day > 31 && month % 2 != 0 && month < 8)
		|| (day > 30 && month % 2 == 0 && month < 8)
		|| (day > 31 && month % 2 == 0 && month >= 8)
		|| (day > 30 && month % 2 != 0 && month > 8)
		|| (day > 29 && month == 2))
		return (false);
	return (true);
}

/**
 * Looks for the correct value into the map.
 * If year is over or under limits, returns the closes date.
 * If date exists on the database (map) returns its value.
 * If it does not exist on the database, looks for the closest lower one and returns its value.
*/
float BitcoinExchange::getValue(std::string date) {
	float ret;

	int year;
	int month;
	int day;

	int dbYear;
	int dbMonth;
	int dbDay;

	year = std::atoi(date.substr(0,4).c_str());
	month = std::atoi(date.substr(5,7).c_str());
	day = std::atoi(date.substr(8,10).c_str());
	if (year > 2022) {
		std::map<std::string, float>::iterator itEnd = _db.end();
		itEnd--;
		return (_db.at(itEnd->first));
	}
	if (year < 2009)
		return (0);

	for (std::map<std::string, float>::iterator it = _db.begin(); it != _db.end(); it++) {
		if (it->first == date)
			return (_db.at(date));
	}

	for (std::map<std::string, float>::iterator it = _db.begin(); it != _db.end(); it++) {
		dbYear = std::atoi(it->first.substr(0,4).c_str());
		dbMonth = std::atoi(it->first.substr(5,7).c_str());
		if (year != dbYear && month != dbMonth)
			continue ;
		int dif = std::numeric_limits<int>::max();
		for (std::map<std::string, float>::iterator it2 = it; (dbMonth == month && dbYear == year); it2++) {
			dbYear = std::atoi(it2->first.substr(0,4).c_str());
			dbMonth = std::atoi(it2->first.substr(5,7).c_str());
			if (dbMonth != month || dbYear != year)
				break ;
			dbDay = std::atoi(it2->first.substr(8,10).c_str());
			if (dif > (day - dbDay) && (day - dbDay) > 0) {
				ret = it2->second;
				dif = day - dbDay;
			}
		}
	}
	return (ret);
}

void BitcoinExchange::convertData(const char *infile_name) {
	_dbFile.open("data.csv");
	if (_dbFile.fail()) {
		std::cout << "Error: Wrong database file." << std::endl;
		return ;
	}
	fillDataBase();

	_infile.open(infile_name);
	if (_infile.fail()) {
		std::cout << "Error: File could not be opened." << std::endl;
		return ;
	}

	std::string line;
	std::string key;
	std::string date;
	float val;

	while (std::getline(_infile, line)) {
		if (line == "date | value")
			continue ;
		if (!validDate(line) || line.size() < 14) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = line.substr(0,10);
		val = std::atof(line.substr(13, line.size()).c_str());
		if (val < 0) {
			std::cout << "Error: not a positivie number." << std::endl;
			continue ;
		} else if (val > 1000) {
			std::cout << "Error: too large number." << std::endl;
			continue ;
		}
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << date << " => " << val << " = " << val * getValue(date) << std::endl;
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


