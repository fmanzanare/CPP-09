/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:12:50 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/07 15:33:29 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange {
	private:
		static std::map<std::string, float> _db;
		static std::map<std::string, float> _input;
		static std::ifstream _dbFile;
		static std::ifstream _infile;
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange &operator=(const BitcoinExchange &cp);
		static void fillDataBase(void);
		static bool validDate(std::string line);
	public:
		static void convertData(const char *infile_name);
};

#endif
