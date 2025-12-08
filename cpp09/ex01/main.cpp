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

static int	checkArguments(int argc, char **argv)
{
	if (argc < 2 || argc > 10)
		return (std::cerr << "Error: No rights arguments provided." << std::endl, 0);
	return (0);
}

int	main(int argc, char** argv)
{
	if (!checkArguments(argc, argv))
		return (1);
	RPN	*rpn = new RPN();
	delete	rpn;
	return (0);
}