#include "Span.hpp"
#include <iostream>
#include <vector>
#include <climits>

int main()
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span range(10000);
	std::vector<int> values;
	for (int i = 0; i < 10000; ++i)
		values.push_back(i * 2);
	range.addRange(values.begin(), values.end());
	std::cout << range.shortestSpan() << std::endl;
	std::cout << range.longestSpan() << std::endl;

	try
	{
		Span small(1);
		small.shortestSpan();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span copy(range);
	Span assigned(1);
	assigned = range;
	std::cout << copy[0] << std::endl;
	std::cout << assigned.getValMin() << std::endl;

	try
	{
		copy[10000];
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
