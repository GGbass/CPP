/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:11:44 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/06 00:12:37 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#endif
