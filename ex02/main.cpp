/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:20:32 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/09 12:35:09 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Error: No enough arguments." << std::endl;
		return (1);
	}

	PmergeMe::sort(argv);

	return (0);
}
