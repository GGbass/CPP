/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:22:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 00:22:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie*	Horde = NULL;
	if (name.empty())
	{
		std::cout << "Invalid name!" << std::endl;
		return (NULL);
	}
	if (n <= 0)
	{
		std::cout << "Invalid number of zombies!" << std::endl;
		return (NULL);
	}
	Horde = new Zombie[n];
	if (!Horde)
	{
		std::cout << "Allocation failed!" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < n; i++)
		Horde[i].setName(name);
	return (Horde);
}
