#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <stdexcept>
#include <algorithm>

template <typename T>
int easyfind(T &container, int target) {

	if (container.begin() == container.end())
		throw std::invalid_argument(RED "ERROR: No arguments" RESET);

	typename T::iterator result = std::find(container.begin(), container.end(), target);

	if (result != container.end())
		return *result;
	else
		throw std::invalid_argument(RED "ERROR: Not found" RESET);
}


#endif