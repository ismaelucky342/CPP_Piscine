/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:44:30 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

namespace
{
	bool	isDigits(std::string const &str, size_t start, size_t length)
	{
		for (size_t i = start; i < start + length; ++i)
		{
			if (!std::isdigit(static_cast<unsigned char>(str[i])))
				return (false);
		}
		return (true);
	}

	bool	isLeapYear(int year)
	{
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	}

	int	daysInMonth(int year, int month)
	{
		static int const	days[12] = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};

		if (month == 2 && isLeapYear(year))
			return (29);
		return (days[month - 1]);
	}

	bool	isValidDate(std::string const &date)
	{
		int	year;
		int	month;
		int	day;

		if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			return (false);
		if (!isDigits(date, 0, 4) || !isDigits(date, 5, 2)
			|| !isDigits(date, 8, 2))
			return (false);
		year = std::atoi(date.substr(0, 4).c_str());
		month = std::atoi(date.substr(5, 2).c_str());
		day = std::atoi(date.substr(8, 2).c_str());
		if (month < 1 || month > 12)
			return (false);
		return (day >= 1 && day <= daysInMonth(year, month));
	}

	bool	parseValue(std::string const &text, double &value)
	{
		size_t	i;
		bool	hasDigit;

		if (text.empty())
			return (false);
		i = 0;
		if (text[i] == '+' || text[i] == '-')
			++i;
		hasDigit = false;
		bool	hasDot = false;
		for (; i < text.size(); ++i)
		{
			if (std::isdigit(static_cast<unsigned char>(text[i])))
				hasDigit = true;
			else if (text[i] == '.' && !hasDot)
				hasDot = true;
			else
				return (false);
		}
		if (!hasDigit)
			return (false);
		value = std::atof(text.c_str());
		return (true);
	}

	bool	parseDatabaseLine(std::string const &line, std::string &date, double &rate)
	{
		std::pair<std::string, std::string>	parts;

		parts = split(line, ',');
		date = removeSpaces(parts.first);
		if (parts.second.empty() || !isValidDate(date))
			return (false);
		return (parseValue(removeSpaces(parts.second), rate));
	}
}

BitcoinExchange::BitcoinExchange(std::string input)
{
	loadDatabase("data.csv");
	processInput(input);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		this->_data = rhs._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::loadDatabase(std::string const &path)
{
	std::ifstream	file(path.c_str());
	std::string		line;

	if (!file.is_open())
		file.open("CPP_Module_09/ex00/data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database." << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string	date;
		double		rate;

		if (parseDatabaseLine(line, date, rate))
			insert(date, rate);
	}
	file.close();
}

void	BitcoinExchange::processInput(std::string const &path)
{
	std::ifstream	file(path.c_str());
	std::string		line;
	bool			firstLine;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			std::string	trimmed = removeSpaces(line);
			if (trimmed.find("date") != std::string::npos
				&& trimmed.find("value") != std::string::npos)
				continue ;
		}
		std::pair<std::string, std::string>	parts = split(line, '|');
		std::string	date = removeSpaces(parts.first);
		std::string	valueText = removeSpaces(parts.second);
		double		value;

		if (parts.second.empty() || !isValidDate(date) || !parseValue(valueText, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator it = _data.lower_bound(date);
		if (it == _data.end())
		{
			if (_data.empty())
			{
				std::cerr << "Error: no data found for date " << date << std::endl;
				continue ;
			}
			--it;
		}
		else if (it->first != date)
		{
			if (it == _data.begin())
			{
				std::cerr << "Error: no data found for date " << date << std::endl;
				continue ;
			}
			--it;
		}
		std::cout << date << " => " << valueText << " = "
			<< value * it->second << std::endl;
	}
	file.close();
}

void	BitcoinExchange::insert(std::string date, double value)
{
	this->_data.insert(std::pair<std::string, double>(date, value));
}

double	BitcoinExchange::getExchangeRate(std::string date) const
{
	std::map<std::string, double>::const_iterator it = this->_data.lower_bound(date);

	if (it == _data.end())
	{
		if (_data.empty())
			return (0);
		--it;
	}
	else if (it->first != date)
	{
		if (it == _data.begin())
			return (0);
		--it;
	}
	return (it->second);
}

std::pair<std::string, std::string>	split(std::string str, char delimiter)
{
	std::pair<std::string, std::string>	pair;
	size_t								start;

	start = str.find(delimiter);
	if (start == std::string::npos)
		return (pair);
	if (str.find(delimiter, start + 1) != std::string::npos)
		return (pair);
	pair.first = str.substr(0, start);
	pair.second = str.substr(start + 1);
	return (pair);
}

std::string	removeSpaces(std::string str)
{
	const std::string space = " \n\r\t";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return (str);
}
