/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:32:39 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/23 22:16:43 by gongarci         ###   ########.fr       */
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
		// const_iterator begin() const { return (this->c.begin());}
		// const_iterator end() const { return (this->c.begin());}
};

#include "MutantStack.tpp"
#endif // MutantStack_HPP
