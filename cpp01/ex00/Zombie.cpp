/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:52:14 by marvin            #+#    #+#             */
/*   Updated: 2025/04/23 16:52:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{

	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " Deleted!" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
