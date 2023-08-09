/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:02:09 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/09 17:30:45 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_v = std::vector<int>();
std::list<int> PmergeMe::_l = std::list<int>();
int PmergeMe::_N = 0;

bool PmergeMe::checkInputs(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}

	return (true);
}

bool PmergeMe::fillContainers(char **argv) {
	long num;

	for (int i = 1; argv[i] != NULL; i++) {
		if (!checkInputs(argv[i])) {
			std::cout << "Error: Wrong arguments." << std::endl;
			return (false);
		}
		num = std::atol(argv[i]);
		if (num > std::numeric_limits<int>::max() || num < 0) {
			std::cout << "Error: Wrong arguments." << std::endl;
			return (false);
		}
		_N++;
		_v.push_back(static_cast<int>(num));
		_l.push_back(static_cast<int>(num));
	}
	return (true);
}

bool PmergeMe::checkSorted() {
	for (std::vector<int>::iterator it = _v.begin(); (it + 1) != _v.end(); it++) {
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}

void PmergeMe::printLExecTime(struct timeval l_start, double dm_time) {
	struct timeval l_end;

	gettimeofday(&l_end, NULL);

	double l_diff = (l_start.tv_sec - l_end.tv_sec) * 1e6;
	l_diff = (l_diff + (l_start.tv_usec - l_start.tv_usec)) * 1e-6;
	if (l_diff < 0)
		l_diff *= -1;

	std::cout << std::fixed;
	std::cout << std::setprecision(6);
	std::cout << "Time to process a range of " << _N << " elements with std::list<int>: " << (l_diff + dm_time) << " secs" << std::endl;
}

void PmergeMe::printVExecTime(struct timeval v_start, double dm_time) {
	struct timeval v_end;

	gettimeofday(&v_end, NULL);

	double v_diff = (v_start.tv_sec - v_end.tv_sec) * 1e6;
	v_diff = (v_diff + (v_start.tv_usec - v_start.tv_usec)) * 1e-6;
	if (v_diff < 0)
		v_diff *= -1;

	std::cout << std::fixed;
	std::cout << std::setprecision(6);
	std::cout << "Time to process a range of " << _N << " elements with std::vector<int>: " << (v_diff + dm_time) << " secs" << std::endl;
}

void PmergeMe::sort(char **argv) {
	struct timeval v_start;
	struct timeval l_start;
	struct timeval dm_start;
	struct timeval dm_end;

	gettimeofday(&dm_start, NULL);

	if (!fillContainers(argv))
		return ;

	gettimeofday(&dm_end, NULL);
	double dm_diff = (dm_start.tv_sec - dm_end.tv_sec) * 1e6;
	dm_diff = (dm_diff + (dm_start.tv_usec - dm_start.tv_usec)) * 1e-6;
	if (dm_diff < 0)
		dm_diff *= -1;

	if (checkSorted()) {
		gettimeofday(&v_start, NULL);
		gettimeofday(&l_start, NULL);

		std::cout << "Before: ";
		for (int i = 1; argv[i] != NULL; i++) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "After: ";
		for (int i = 1; argv[i] != NULL; i++) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
		printVExecTime(v_start, dm_diff);
		printLExecTime(l_start, dm_diff);
		return ;
	}
}

/*
	The class is static and it cannot be instantiated.
	(Constructors, destructor and assignation operator are private)
*/
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cp) { *this = cp; }

PmergeMe &PmergeMe::operator=(const PmergeMe &cp) { (void)cp; return (*this); }
