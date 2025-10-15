/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:41:13 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/15 20:50:21 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0)
{
	std::cout << "Decault Span constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other)
{
	if (this != &other)
	{
		this->_vect = (other._vect);
		std::cout << "Copy constructor called" << std::endl;
	}
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_vect = (other._vect);
		std::cout << "Asssigning operator called" << std::endl;
	}
}


Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}
