/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:36:22 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << RED "Error" RESET << std::endl;
		return (1);
	}

	try
	{
		PmergeMe pm(ac, av);
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Error" RESET << std::endl;
		return (1);
	}
	return (0);
}
