/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 01:34:27 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/12 01:34:27 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T>
void	easyfind(T &x, int y);
void	printFounded(int indx, int toFind);

struct NotFoundException : std::exception
{
	public:
		virtual const char *what() const throw();
};

#include "easyfind.tpp"

#endif
