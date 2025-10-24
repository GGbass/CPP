/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 02:42:50 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/20 02:42:50 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	mainGiven(void)
{
	std::cout << "----- Main Given -----|" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	copyTest()
{
	std::cout << "-----Copy Test -----|" << std::endl;
	MutantStack<std::string> *str =  new MutantStack<std::string>();
	str->push("hello");
	str->push("world");
	MutantStack<std::string> *stackCopy = new MutantStack<std::string>(*str);
	
	std::cout << *str << std::endl;
	delete str;
	std::cout << *stackCopy << std::endl;
	MutantStack<std::string> *stackAssign = new MutantStack<std::string>();
	*stackAssign = *stackCopy;
	delete stackCopy;
	std::cout << *stackAssign << std::endl;

	delete stackAssign;

}

int	main(void)
{
	mainGiven();
	//copyTest();
	return 0;
}
