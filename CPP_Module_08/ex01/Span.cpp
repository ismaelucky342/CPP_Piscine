/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:32:20 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/19 14:09:51 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <limits>

Span::Span()
	: _store(), _nMax(0), _lenStored(0), _valMin(INT_MAX), _valMax(INT_MIN)
{}

Span::Span(unsigned int n)
	: _store(), _nMax(n), _lenStored(0), _valMin(INT_MAX), _valMax(INT_MIN)
{}

Span::Span(Span const &src)
	: _store(src._store), _nMax(src._nMax), _lenStored(src._lenStored),
	  _valMin(src._valMin), _valMax(src._valMax)
{}

Span::~Span()
{}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_store = src._store;
		_nMax = src._nMax;
		_lenStored = src._lenStored;
		_valMin = src._valMin;
		_valMax = src._valMax;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_lenStored >= _nMax)
		throw std::overflow_error("Span: span is full");
	_store.push_back(number);
	_lenStored = _store.size();
	if (_lenStored == 1)
	{
		_valMin = number;
		_valMax = number;
	}
	else
	{
		if (number < _valMin)
			_valMin = number;
		if (number > _valMax)
			_valMax = number;
	}
}

int Span::shortestSpan()
{
	if (_lenStored < 2)
		throw std::invalid_argument("Span: not enough numbers");

	std::vector<int> sorted = _store;
	std::sort(sorted.begin(), sorted.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i + 1 < sorted.size(); ++i)
	{
		long long difference = static_cast<long long>(sorted[i + 1]) - sorted[i];
		if (difference < shortest)
			shortest = static_cast<int>(difference);
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_lenStored < 2)
		throw std::invalid_argument("Span: not enough numbers");
	long long difference = static_cast<long long>(_valMax) - _valMin;
	if (difference > std::numeric_limits<int>::max())
		return std::numeric_limits<int>::max();
	return static_cast<int>(difference);
}

int &Span::operator[](unsigned int index)
{
	if (index >= _lenStored)
		throw std::out_of_range("Span: index out of bounds");
	return _store[index];
}

int Span::getValMin() const
{
	return _valMin;
}

int Span::getValMax() const
{
	return _valMax;
}

std::vector<int>::iterator Span::begin()
{
	return _store.begin();
}

std::vector<int>::iterator Span::end()
{
	return _store.end();
}
