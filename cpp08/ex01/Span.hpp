/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:41:07 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/15 20:45:49 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
#define Span_HPP
#include <iostream>
#include <vector>


class Span
{
	private:
		unsigned int			_n;
		std::vector<int>		_vect;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		/* methods */
		void	addNumbers(unsigned int n);
};

#endif // Span_HPP
