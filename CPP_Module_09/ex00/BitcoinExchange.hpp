/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:44:35 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*=================================INCLUDES==================================*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

/*================================COLORS=====================================*/

# define RESET "\033[0m"
# define RED "\033[31m"

/*================================CLASS=====================================*/

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;

		void	loadDatabase(std::string const &path);
		void	processInput(std::string const &path);

	public:
		BitcoinExchange(std::string input);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		void	insert(std::string date, double value);
		double	getExchangeRate(std::string date) const;
};

/*================================FUNCTIONS=================================*/

std::string							removeSpaces(std::string str);
std::pair<std::string, std::string>	split(std::string str, char delimiter);

#endif
