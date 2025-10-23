/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:32:43 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/23 22:17:47 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T>(std::deque<T>(other))
{
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T,Container>::operator=(const MutantStack &other)
{
	if (this != &other)
	{
		this = std::stack<T>::operator=(other); //check later this line
		std::cout << "Assigning operator called" << std::endl;
	}
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
	return (this->c.end());
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "Destructor called" << std::endl;
}
