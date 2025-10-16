/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:41:13 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/17 01:26:31 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0), _minValue(0), _maxValue(0)
{
	std::cout << "Decault Span constructor called" << std::endl;
}

Span::Span(unsigned int n) : _size(n), _minValue(0), _maxValue(0)
{

	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other)
{
	if (this != &other)
	{
		this->_vect = other._vect;
		this->_minValue = other._minValue;
		this->_maxValue = other._maxValue;
		std::cout << "Copy constructor called" << std::endl;
	}
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_vect = (other._vect);
		this->_minValue = other._minValue;
		this->_maxValue = other._maxValue;
		std::cout << "Asssigning operator called" << std::endl;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

int	Span::getMinValue() const { return (this->_minValue);}
int	Span::getMaxValue() const { return (this->_maxValue);}

const char* Span::MaxCapacityExceeded::what() const throw ()
{
	return ("Max capacity exceeded \n");
}

void	Span::addNumber(int n)
{
	if (this->_vect.size() >= this->_size)
		throw MaxCapacityExceeded();
	this->_vect.push_back(n);
	if (this->_vect.size() == 1)
	{
		this->_minValue = n;
		this->_maxValue = n;
	}
	if (n > this->_maxValue)
		this->_maxValue = n;
	if (n < this->_minValue)
		this->_minValue = n;
}


unsigned int	Span::getNumber(unsigned int index) const
{
	if (index < this->_size)
		return (this->_vect[index]);
	return (0);
}

int	Span::getSize() const {return (this->_size);}

std::ostream& operator<<(std::ostream& os, const Span &span)
{
	std::cout << "vector size: = " << span.getSize() << std::endl;
	os << "{";
	for (unsigned i = 0; i < (unsigned int)span.getSize(); i++)
	{
		os << span.getNumber(i);
		if (i + 1 < (unsigned int)span.getSize())
			os << ", ";
	}
	return (os << "}" << std::endl);
}
/* 
int	Span::secondMinValue(void)
{
	int	secondMin = this->_minValue;
	for (int i = 0; i < this->_size; i++)
	{
		if (secondMind > this->_vect[i])
			secondMin = this->_vect[i];
	}
	return (secondMin);
} */

int	Span::shortestSpan(void)
{
	if (this->_size <= 1)
		throw std::invalid_argument("Error: Wrong size of numbers for a Span");
	
	return (0);
}

int	Span::longestSpan(void)
{
	if (!this->_size || this->_size == 1)
		throw std::invalid_argument("Error: Wrong size of numbers for a Span");
	return (this->_maxValue - this->_minValue);
}
