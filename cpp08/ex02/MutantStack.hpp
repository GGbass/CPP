/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:32:39 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/24 09:56:57 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
#define MutantStack_HPP
# include <stack>
# include <deque>
# include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &);
		MutantStack& operator=(const MutantStack &);
		~MutantStack();
		/* Methods */
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};
template <typename T, typename Container = std::deque<T> >
std::ostream& operator<<(std::ostream &os, MutantStack<T, Container> const &src);

#include "MutantStack.tpp"
#endif
