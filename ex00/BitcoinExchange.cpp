/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:12:48 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/03 17:01:10 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_db = std::map<std::string, float>();
std::map<std::string, float> BitcoinExchange::_input = std::map<std::string, float>();
std::ifstream BitcoinExchange::_db_file = std::ifstream("data.csv");
std::ifstream BitcoinExchange::_infile = std::ifstream();

void BitcoinExchange::convertData(const char *infile_name) {
	_infile.open(infile_name); // Try to pass a wrong file and check behaviour!!!!!

}

















/*
	The class is static and it cannot be instantiated.
	(Constructors, destructor and assignation operator are private)
*/
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp) { (void)cp; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cp) { (void)cp; return (*this); }


