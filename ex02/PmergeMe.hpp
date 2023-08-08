/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:59:52 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/08 18:37:50 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
	private:
		static std::vector<int> _v;
		static std::list<int> _l;
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe &operator=(const PmergeMe &cp);
	public:
		static void sort(const char **argv);
};

#endif
