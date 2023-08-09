/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:02:09 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/09 20:29:07 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_v = std::vector<int>();
std::list<int> PmergeMe::_l = std::list<int>();
int PmergeMe::_N = 0;

/**
 * Checks if the inputs are numbers.
 * If a number is not found on it, it returns false.
 * @param *str String to be checked.
 * @return true, if the string only contains numbers, false if it contains something more.
*/
bool PmergeMe::checkInputs(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}

	return (true);
}

/**
 * Fills the class containers with the received arguments.
 * If the argument is negative, or if its not a number, it prints an error and return false.
 * @param **argv Received arguments from main function.
 * @return true if arguments are right, false if there are wrong arguments.
*/
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

/**
 * Goes through each element of the class vector to check if it is already sorted.
 * @return true, if it is sortes, false if it is not.
*/
bool PmergeMe::checkSorted() {
	for (std::vector<int>::iterator it = _v.begin(); (it + 1) != _v.end(); it++) {
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}

/**
 * Get the execution time for a particular contianer.
 * @param start Timeval struct that saves the starting time.
 * @param end Timeval struct that saves the finishing time.
 * @param dm_time Data management time previously calculated.
*/
double PmergeMe::getExecTime(struct timeval start, struct timeval end, double dm_time) {
	gettimeofday(&end, NULL);

	double diff = (start.tv_sec - end.tv_sec) * 1e6;
	diff = (diff + (start.tv_usec - end.tv_usec)) * 1e-6;
	if (diff < 0)
		diff *= -1;

	return (diff + dm_time);
}

/**
 * Recives a vector and sorts it.
 * If its size is lower or equal to 180 elements, it does insertion sort.
 * If not, it calls the function recursively until each section can be sorted with insertion sort.
 * @param vector Received unordered vector.
 * @return sorted vector.
*/
std::vector<int> PmergeMe::vectorSort(std::vector<int> vector) {
	// INSERTION SORT.
	if (vector.size() <= 180) {
		int fixed;
		int tmp;

		for (int i = 1; i < (int)vector.size(); i++) {
			tmp = vector[i];
			fixed = i - 1;

			while (fixed >= 0 && vector[fixed] > tmp) {
				vector[fixed + 1] = vector[fixed];
				fixed--;
			}
			vector[fixed + 1] = tmp;
		}
		return (vector);
	}

	// MERGE SORT.
	std::vector<int>::iterator midpoint = vector.begin() + (vector.size() / 2);
	std::vector<int> leftSect = std::vector<int>(vector.begin(), midpoint);
	std::vector<int> rightSect = std::vector<int>(midpoint, vector.end());

	leftSect = vectorSort(leftSect);
	rightSect = vectorSort(rightSect);

	std::vector<int> res;
	std::merge(leftSect.begin(), leftSect.end(), rightSect.begin(), rightSect.end(), std::back_inserter(res));
	return (res);
}

/**
 * Recives a list and sorts it.
 * If its size is lower or equal to 180 elements, it does insertion sort.
 * If not, it calls the function recursively until each section can be sorted with insertion sort.
 * @param list Received unordered list.
 * @return sorted list.
*/
std::list<int> PmergeMe::listSort(std::list<int> list) {
	// INSERTION SORT.
	if (list.size() <= 180) {
		for (std::list<int>::iterator it = ++list.begin(); it != list.end(); ) {
			std::list<int>::iterator fixed = it;
			std::advance(fixed, -1);
			while (fixed != list.begin() && *fixed > *it)
				--fixed;
			if (*fixed < *it)
				++fixed;
			if (*fixed >= *it) {
				list.insert(fixed, *it);
				it = list.erase(it);
			} else
				it++;
		}
			return (list);
	}

	// MERGE SORT.
	std::list<int>::iterator midpoint = list.begin();
	std::advance(midpoint, (std::distance(list.begin(), list.end()) / 2));
	std::list<int> leftSect = std::list<int>(list.begin(), midpoint);
	std::list<int> rightSect = std::list<int>(midpoint, list.end());

	leftSect = listSort(leftSect);
	rightSect = listSort(rightSect);

	std::list<int> res;
	std::merge(leftSect.begin(), leftSect.end(), rightSect.begin(), rightSect.end(), std::back_inserter(res));
	return (res);
}

/**
 * Gets the received arguments, parses them, fills the containers, and sorts them.
 * If the received argument is sorted, then prints them and prints the execution time.
 * To calculate the execution time, it adds the data management time (dm_*) and the sorting time (v_*, _l*).
 * Finally, if the arguments are not sorted, it calls the sorting functions for each container.
 * @param **argv Received arguments from main function.
*/
void PmergeMe::sort(char **argv) {
	struct timeval v_start;
	struct timeval v_end;
	struct timeval l_start;
	struct timeval l_end;
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

		gettimeofday(&v_end, NULL);
		gettimeofday(&l_end, NULL);

		std::cout << std::fixed;
		std::cout << std::setprecision(5);
		std::cout << "Time to process a range of " << _N << " elements with std::vector<int>: " << getExecTime(v_start, v_end, dm_diff) << " secs" << std::endl;
		std::cout << "Time to process a range of " << _N << " elements with std::list<int>: " << getExecTime(l_start, l_end, dm_diff) << " secs" << std::endl;

		return ;
	}

	std::cout << "Before: ";
	for (int i = 1; argv[i] != NULL; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	// MERGE-INSERT SORT FOR std::vector<int> CONTAINER
	gettimeofday(&v_start, NULL);
	_v = vectorSort(_v);
	std::cout << "After std::vector<int>: ";
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	gettimeofday(&v_end, NULL);

	// MERGE-INSERT SORT FOR std::list<int> CONTAINER
	gettimeofday(&l_start, NULL);
	_l = listSort(_l);
	std::cout << "After std::list<int>: ";
	for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	gettimeofday(&l_end, NULL);

	std::cout << std::fixed;
	std::cout << std::setprecision(5);
	std::cout << "Time to process a range of " << _N << " elements with std::vector<int>: " << getExecTime(v_start, v_end, dm_diff) << " secs" << std::endl;
	std::cout << "Time to process a range of " << _N << " elements with std::list<int>: " << getExecTime(l_start, l_end, dm_diff) << " secs" << std::endl;
}

/*
	The class is static and it cannot be instantiated.
	(Constructors, destructor and assignation operator are private)
*/
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cp) { *this = cp; }

PmergeMe &PmergeMe::operator=(const PmergeMe &cp) { (void)cp; return (*this); }
