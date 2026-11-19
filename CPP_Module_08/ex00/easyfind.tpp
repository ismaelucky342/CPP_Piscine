#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(T const &container, int target)
{
	if (container.begin() == container.end())
		throw std::invalid_argument("easyfind: empty container");

	typedef typename T::const_iterator ConstIterator;
	ConstIterator result = std::find(container.begin(), container.end(), target);
	if (result == container.end())
		throw std::invalid_argument("easyfind: value not found");
	return *result;
}

#endif