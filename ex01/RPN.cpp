/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:57:53 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/08 16:43:53 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::stk = std::stack<int>();

/**
 * Checks if the received argument contains something that is not number, operator or spaces.
 * If something is found, it returns false, to show an error message.
 * Otherwise, it returns true.
*/
bool RPN::checker(const char *str) {
	while (*str) {
		if ((*str < '0' || *str > '9')
			&& *str != '+' && *str != '-' && *str != '*' && *str != '/'
			&& *str != ' ')
			return (false);
		str++;
	}
	return (true);
}

/**
 * First, checks the received argument to see if everything is ok.
 * Then, it goes through the received argument and fills the stack with the digits.
 * If an operator is found, it operates over the two top elements of the stack.
 * Once an operation is done, the new top of the stack is its result.
*/
void RPN::operate(const char *str) {
	if (!checker(str)) {
		std::cout << "Error" << std::endl;
		return ;
	}

	while(*str) {
		if (*str >= '0' && *str <= '9')
			stk.push(*str - 48);
		else if (*str == '+' || *str == '-' || *str == '*' || *str == '/') {
			if (stk.size() <= 1) {
				std::cout << "Error. Too many operation and too few operands." << std::endl;
				return ;
			}
			int rOperand1 = stk.top();
			stk.pop();
			int rOperand2 = stk.top();
			stk.pop();
			if (*str == '+')
				stk.push(rOperand2 + rOperand1);
			else if (*str == '-')
				stk.push(rOperand2 - rOperand1);
			else if (*str == '*')
				stk.push(rOperand2 * rOperand1);
			else if (*str == '/')
				stk.push(rOperand2 / rOperand1);
		}
		str++;
	}
	std::cout << "RPN result: " << stk.top() << std::endl;
}

/*
	The class is static and it cannot be instantiated.
	(Constructors, destructor and assignation operator are private)
*/
RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &cp) { *this = cp; }

RPN &RPN::operator=(const RPN &cp) { (void)cp; return (*this); }
