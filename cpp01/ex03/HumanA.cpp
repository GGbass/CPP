/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:00:54 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 18:00:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon::weapon )
{
	this->name = name;
	//this->weapon = weapon;
}

HumanA::attack(void)
{
	std::cout << "attack! " << name << weapon.getType() << std::endl;
}
