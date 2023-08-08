/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:57:45 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/08 18:03:51 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdlib.h>
#include <iostream>

class RPN {
	private:
		static std::stack<int> _stk;
		RPN();
		~RPN();
		RPN(const RPN &cp);
		RPN &operator=(const RPN &cp);
		static bool checker(const char *str);
	public:
		static void operate(const char *str);
};

#endif
