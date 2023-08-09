/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:59:52 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/09 17:29:42 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <limits>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
	private:
		static std::vector<int> _v;
		static std::list<int> _l;
		static int _N;
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &cp);
		static bool checkInputs(char *str);
		static bool fillContainers(char **argv);
		static bool checkSorted(void);
		static void printVExecTime(struct timeval v_start, double dm_time);
		static void printLExecTime(struct timeval l_start, double dm_time);
	public:
		static void sort(char **argv);
};

#endif
