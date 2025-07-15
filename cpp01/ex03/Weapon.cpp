/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:45:36 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 17:45:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (const std::string& type)
{
	this->type = type;
}

std::string	Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
