/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:08:51 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/08 00:43:48 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#define IS_OP(c) (c == '+' || c == '-' || c == '*' || c == '/')
#include <iostream>
#include <stack>
#include <stdexcept>
#include <algorithm>

class	RPN
{
	private:
		// Private members and methods can be declared here
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
};

#endif // RPN_HPP
