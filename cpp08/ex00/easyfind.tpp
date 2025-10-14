/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 01:34:36 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/15 00:29:03 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"

void	printFounded(int indx, int toFind)
{
	std::cout << "Element: "
			 << toFind << " founded in Index: " 
			 << indx << std::endl;
}

template <typename T>
void	easyfind(T	&x, int	toFind)
{
	if (x.empty())
		return (std::cout << "Empty container" << std::endl, void());
	typename T::iterator check = std::find(x.begin(), x.end(), toFind);
	std::cout << &check << std::endl;
	if (check == x.end())
	{
		throw NotFoundException();
	}
	size_t index = std::distance(x.begin(), check);
	printFounded(static_cast<int>(index + 1), toFind);
}

const char* NotFoundException::what() const throw()
{
	return ("Element it's not inside of the container");
}
#endif
