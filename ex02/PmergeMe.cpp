/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:02:09 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/08 18:07:31 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_v = std::vector<int>();
std::list<int> PmergeMe::_l = std::list<int>();

void PmergeMe::sort(const char **argv) {

}

/*
	The class is static and it cannot be instantiated.
	(Constructors, destructor and assignation operator are private)
*/
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cp) { *this = cp; }

PmergeMe &PmergeMe::operator=(const PmergeMe &cp) { (void)cp; return (*this); }
