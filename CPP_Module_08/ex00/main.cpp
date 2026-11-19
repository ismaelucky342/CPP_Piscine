/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:23 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/19 14:16:43 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(17);
	vector.push_back(3);

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	list.push_back(3);

	std::deque<int> deque;
	deque.push_back(5);
	deque.push_back(17);
	deque.push_back(3);

	std::cout << easyfind(vector, 17) << std::endl;
	std::cout << easyfind(list, 3) << std::endl;
	std::cout << easyfind(deque, 5) << std::endl;

	try
	{
		easyfind(vector, 42);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int> empty;
		easyfind(empty, 42);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

