/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:08:32 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/08 20:29:52 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	checkArguments(int argc, char **argv)
{
	int	size = 0;
	if (argc != 2)
		return (std::cerr << "Error: No rights arguments provided." << std::endl, 0);
	for (int i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] == ' ') {continue;}
		if (!isdigit(argv[1][i]) && !IS_OP(argv[1][i]))
			return (std::cerr << "Error" << std::endl, 0);
		if (IS_OP(argv[1][i])) {size++;}
		if (size > 10)
			return (std::cerr << "Error: Too many operations provided." << std::endl, 0);
	}
	return (1);
}

int	main(int argc, char** argv)
{
	if (!checkArguments(argc, argv))
		return (1);
	RPN	*rpn = new RPN();
	try
	{
		rpn->run(static_cast<std::string>(argv[1]));
		std::cout << "Result: " << rpn->getResult() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	delete rpn;
	return (0);
}