/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:08:51 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/08 20:00:10 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#define IS_OP(c) (c == '+' || c == '-' || c == '*' || c == '/')
#include <iostream>
// #include <algorithm>
#include <stack>
#include <stdexcept>

class	RPN
{
	private:
		std::stack<int>	_stack;
		int				doOps(char op, int left, int right);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		int	run(std::string input);
		int	getResult() const;
};

std::ostream& operator<<(std::ostream& os, const RPN& rpn);

#endif // RPN_HPP
