/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:11:36 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 18:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon;
}

HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

HumanB::attack(void)
{
	std::cout << "attack! " << name << weapon.getType() << std::endl;
}
