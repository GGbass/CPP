/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:41:07 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/19 21:20:37 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
#define Span_HPP
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cstdlib>

class Span
{
	private:
		std::vector<int>		_vect;
		unsigned int			_size;
		int						_minValue;
		int						_maxValue;
		int						_stored;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		/* methods */
		void		printNumbers();
		int			shortestSpan();
		int			longestSpan();
		int			getMinValue() const;
		int			getMaxValue() const;
		int			getSize() const;
		void		addNumber(int n);
		template <typename Iterator>
		void		addNumbers(Iterator begin, Iterator end)
		{
			for (;begin != end ; begin++)
				this->addNumber(*begin);
			std::cout << "Add Numbers check \n" << std::endl;
		}
		unsigned int		getNumber(unsigned int index) const;
};

std::ostream& operator<<(std::ostream& os, const Span &span);

#endif // Span_HPP
