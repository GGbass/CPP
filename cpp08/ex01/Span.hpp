/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:41:07 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/18 19:12:29 by gongarci         ###   ########.fr       */
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
			for (;begin != end ; ++begin)
				this->addNumber(*begin);
			std::cout << "Add Numbers check \n" << std::endl;
		}
		unsigned int		getNumber(unsigned int index) const;
};

std::ostream& operator<<(std::ostream& os, const Span &span);

#endif // Span_HPP


/* to do
	For longestSpan(), return max_element(v.begin(), v.end()) - min_element(v.begin(), v.end()); 
	require at least two elements.

	For shortestSpan(), require at least two elements, make a local copy, 
	call std::sort(copy.begin(), copy.end()), then scan once computing adjacent differences and return the minimum adjacent difference.
 	This yields overall O(n log n) due to sorting and O(n) additional scan.

 
 	Quick notes and trade-offs
	Using std::multiset avoids an explicit sort because it keeps values sorted on insert,
	but each insert costs logarithmic time and memory per node; vector + one sort is usually faster and more memory efficient
 	for large bulk inserts.

Use std::vector::reserve(N) up front to avoid reallocations and to respect the fixed capacity policy.
 */