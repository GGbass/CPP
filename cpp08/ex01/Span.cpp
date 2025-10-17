/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:41:13 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/18 01:36:01 by gongarci         ###   ########.fr       */
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

void	Span::printNumbers(void)
{
	if (this->_vect.size())
	{
		for (int i = 0; i < (int)this->_vect.size(); i++)
			std::cout << this->_vect[i] << std::endl;
	}
}

int	Span::getMinValue() const { return (this->_minValue);}
int	Span::getMaxValue() const { return (this->_maxValue);}
int	Span::getSize() const {return (this->_size);}

void	Span::addNumber(int n)
{
	if (this->_vect.size() >= this->_size)
		throw std::invalid_argument("Error: Capacity exceeded\n");
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

std::ostream& operator<<(std::ostream& os, const Span &span)
{
	os << "{";
	for (unsigned i = 0; i < (unsigned int)span.getSize(); i++)
	{
		os << span.getNumber(i);
		if (i + 1 < (unsigned int)span.getSize())
			os << ", ";
	}
	return (os << "}" << std::endl);
}

int	Span::shortestSpan(void)
{
	int	shortest;
	int	gap;
	if (this->_size <= 1)
		throw std::invalid_argument("Error: Wrong size of numbers for a Span");
	std::vector<int> tmp = this->_vect;
	std::sort(tmp.begin(), tmp.end());
	shortest = tmp[1] - tmp.front();
	for (size_t i = 2; i < tmp.size(); i++)
	{
		gap = tmp[i] - tmp[i -1];
		if (gap < shortest)
			shortest = gap;
	}
	return (shortest);
}

int	Span::longestSpan(void)
{
	if (!this->_size || this->_size == 1)
		throw std::invalid_argument("Error: Wrong size of numbers for a Span");
	std::vector<int> tmp = this->_vect;
	std::sort(tmp.begin(), tmp.end());
	return ((tmp.back()) - (tmp.front()));
}
