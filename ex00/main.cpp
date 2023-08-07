/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:40:24 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/07 15:14:02 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

int main(void) {
	std::fstream in("data.csv");

	std::string date;
	float		val;
	std::string word;
	std::string line;
	std::string tmp;
	std::map<std::string, float> map;

	int	i = 0;
	while (std::getline(in, line)) {
		if (i != 0) {
			std::string key = line.substr(0,9);
			float		val = std::atof(line.substr(12,line.size()).c_str());
			map.insert(std::pair<std::string, float>(key, val));
		}
		i++;
	}

	for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}




	return (0);
}
