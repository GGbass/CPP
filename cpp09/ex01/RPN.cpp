/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:08:40 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/08 20:01:54 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{
	
}

int	RPN::run(std::string input)
{
	char	op;
	for (int i = 0; input[i]; i++)
	{
		op = input[i];
		if (op == ' ') {continue;}
		else if (isdigit(input[i]))
			this->_stack.push(op - '0');
		else if (IS_OP(op))
		{
			if (this->_stack.size() < 2)
				throw std::runtime_error("Not enough operands.");
			int	right = _stack.top();
			_stack.pop();
			int	left = _stack.top();
			_stack.pop();
			this->_stack.push(doOps(op, left, right));
		}
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("The user input has too many operands.");
	return (1);
}


/* private tools */

int	RPN::doOps(char op, int left, int right)
{
	switch (op)
	{
		case '+':
			return (left + right);
		case '-':
			return (left - right);
		case '*':
			return (left * right);
		case '/':
			if (right == 0)
				throw std::runtime_error("Division by zero.");
			return (left / right);
		default:
			throw std::runtime_error("Invalid operator.");
	}
}

int	RPN::getResult() const
{
	return (this->_stack.top());
}

std::ostream& operator<<(std::ostream& os, const RPN& rpn)
{
	os << "RPN result: " << rpn.getResult();
	return (os);
}
