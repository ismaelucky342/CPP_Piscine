/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:45:59 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/16 12:00:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <climits>
#include <cctype>
#include <ctime>
#include <iomanip>

namespace
{
	struct Pair
	{
		int	small;
		int	large;
	};

	struct PairLess
	{
		bool	operator()(Pair const &a, Pair const &b) const
		{
			return (a.large < b.large);
		}
	};

	std::vector<size_t>	jacobsthalOrder(size_t size)
	{
		std::vector<size_t>	order;
		size_t				previous;
		size_t				first;
		size_t				second;
		size_t				high;

		if (size <= 1)
			return (order);
		previous = 1;
		first = 1;
		second = 3;
		while (previous < size)
		{
			high = std::min(second, size);
			for (size_t i = high; i > previous; --i)
				order.push_back(i - 1);
			previous = high;
			size_t next = second + 2 * first;
			first = second;
			second = next;
		}
		return (order);
	}

	void	insertPair(std::vector<Pair> &chain, Pair const &value)
	{
		std::vector<Pair>::iterator	position;

		position = std::lower_bound(chain.begin(), chain.end(), value, PairLess());
		chain.insert(position, value);
	}

	void	sortPairs(std::vector<Pair> &pairs)
	{
		if (pairs.size() < 2)
			return ;

		bool				hasStraggler;
		Pair				straggler;
		std::vector<Pair>	small;
		std::vector<Pair>	large;

		hasStraggler = (pairs.size() % 2 != 0);
		if (hasStraggler)
		{
			straggler = pairs.back();
			pairs.pop_back();
		}
		small.reserve(pairs.size() / 2);
		large.reserve(pairs.size() / 2);
		for (size_t i = 0; i + 1 < pairs.size(); i += 2)
		{
			if (pairs[i].large < pairs[i + 1].large)
			{
				small.push_back(pairs[i]);
				large.push_back(pairs[i + 1]);
			}
			else
			{
				small.push_back(pairs[i + 1]);
				large.push_back(pairs[i]);
			}
		}
		sortPairs(large);

		std::vector<Pair>	chain;
		for (size_t i = 0; i < large.size(); ++i)
			chain.push_back(large[i]);
		insertPair(chain, small[0]);
		std::vector<size_t>	order = jacobsthalOrder(small.size());
		for (size_t i = 0; i < order.size(); ++i)
			insertPair(chain, small[order[i]]);
		if (hasStraggler)
			insertPair(chain, straggler);
		pairs.swap(chain);
	}

	template <typename Container>
	void	insertValue(Container &chain, int value)
	{
		typename Container::iterator	position;

		position = std::lower_bound(chain.begin(), chain.end(), value);
		chain.insert(position, value);
	}

	template <typename Container>
	void	mergeInsertionSort(Container &values)
	{
		if (values.size() < 2)
			return ;

		bool	hasStraggler;
		int		straggler;
		std::vector<Pair>	pairs;

		hasStraggler = (values.size() % 2 != 0);
		if (hasStraggler)
		{
			straggler = values.back();
			values.pop_back();
		}
		pairs.reserve(values.size() / 2);
		for (size_t i = 0; i + 1 < values.size(); i += 2)
		{
			Pair pair;
			if (values[i] < values[i + 1])
			{
				pair.small = values[i];
				pair.large = values[i + 1];
			}
			else
			{
				pair.small = values[i + 1];
				pair.large = values[i];
			}
			pairs.push_back(pair);
		}
		sortPairs(pairs);

		Container	chain;
		for (size_t i = 0; i < pairs.size(); ++i)
			chain.push_back(pairs[i].large);
		insertValue(chain, pairs[0].small);
		std::vector<size_t>	order = jacobsthalOrder(pairs.size());
		for (size_t i = 0; i < order.size(); ++i)
			insertValue(chain, pairs[order[i]].small);
		if (hasStraggler)
			insertValue(chain, straggler);
		values.swap(chain);
	}

	bool	parsePositiveInt(std::string const &text, int &value)
	{
		long	result;

		if (text.empty())
			return (false);
		result = 0;
		for (size_t i = 0; i < text.size(); ++i)
		{
			if (!std::isdigit(static_cast<unsigned char>(text[i])))
				return (false);
			result = result * 10 + (text[i] - '0');
			if (result > INT_MAX)
				return (false);
		}
		value = static_cast<int>(result);
		return (true);
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac < 2)
		throw InvalidInput();
	for (int i = 1; i < ac; ++i)
	{
		std::string	text(av[i]);
		int			value;

		if (!parsePositiveInt(text, value) || value <= 0)
			throw InvalidInput();
		add(value);
	}
	if (_vector.empty())
		throw InvalidInput();

	print("Before:");
	clock_t	startVector = std::clock();
	sortVector();
	clock_t	endVector = std::clock();
	clock_t	startDeque = std::clock();
	sortDeque();
	clock_t	endDeque = std::clock();

	print("After:");
	double	timeVector = 1000000.0 * static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC;
	double	timeDeque = 1000000.0 * static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << CYAN << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << timeVector << " us" << RESET << std::endl;
	std::cout << CYAN << "Time to process a range of " << _deque.size()
		<< " elements with std::deque : " << timeDeque << " us" << RESET << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		_vector = src._vector;
		_deque = src._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::add(int n)
{
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		if (_vector[i] == n)
			throw DuplicateNumber();
	}
	_vector.push_back(n);
	_deque.push_back(n);
}

void	PmergeMe::sortVector()
{
	mergeInsertionSort(_vector);
}

void	PmergeMe::sortDeque()
{
	mergeInsertionSort(_deque);
}

void	PmergeMe::print(std::string const &label) const
{
	std::cout << YELLOW << label << RESET << " ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

const char* PmergeMe::InvalidInput::what() const throw()
{
	return ("Invalid input");
}

const char* PmergeMe::DuplicateNumber::what() const throw()
{
	return ("Duplicate number");
}
