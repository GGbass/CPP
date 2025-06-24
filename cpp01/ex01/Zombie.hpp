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
		Zombie(std::string name);
		Zombie(void);
		~Zombie();
		void announce(void);
		void setName(std::string name);

};

Zombie* zombieHorde(int n, std::string name);

#endif