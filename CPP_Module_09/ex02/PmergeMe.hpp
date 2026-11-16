/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:36:55 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*=================================INCLUDES==================================*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>

/*================================COLORS=====================================*/

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"

/*================================CLASS=====================================*/

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	add(int n);
		void	sortVector();
		void	sortDeque();
		void	print(const std::string &label) const;

	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);
		~PmergeMe();

		class InvalidInput : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DuplicateNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
