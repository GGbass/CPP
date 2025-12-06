/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:08:32 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/06 00:08:32 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc == 1)
		return (std::cerr << "Error: invalid number of arguments." << std::endl, 1);

	RPN	*rpn = new RPN();

	delete rpn;
	return (0);
}