/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:27:45 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/19 14:09:51 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

/*================================INCLUDES=================================*/

#include <stdexcept>
#include <vector>
#include <algorithm>

/*================================CLASS=====================================*/

class Span
{
	private:
		std::vector<int> _store;
		unsigned int _nMax;
		unsigned int _lenStored;
		int _valMin;
		int _valMax;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		~Span();
		Span &operator=(Span const &src);

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		int &operator[](unsigned int index);
		int getValMin() const;
		int getValMax() const;
		std::vector<int>::iterator begin();
		std::vector<int>::iterator end();

		template <typename InputIterator>
		void addRange(InputIterator first, InputIterator last)
		{
			for (InputIterator it = first; it != last; ++it)
			{
				if (_lenStored >= _nMax)
					throw std::overflow_error("Span: span is full");
				int number = *it;
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
		}
};

#endif