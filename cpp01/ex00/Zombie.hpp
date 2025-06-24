/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:07:01 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 18:07:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class	Zombie
{
	private:
		std::string name;
		
	public:
		void announce(void);
		Zombie(std::string name);
		~Zombie();
	
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif