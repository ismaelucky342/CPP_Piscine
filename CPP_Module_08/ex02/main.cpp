#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int> copy(mstack);
	MutantStack<int> assigned;
	assigned = mstack;
	const MutantStack<int> &constCopy = copy;
	for (MutantStack<int>::const_iterator cit = constCopy.begin(); cit != constCopy.end(); ++cit)
		std::cout << *cit << std::endl;
	std::cout << assigned.top() << std::endl;

	MutantStack<int, std::list<int> > listStack;
	listStack.push(5);
	listStack.push(17);
	listStack.pop();
	listStack.push(3);
	listStack.push(5);
	listStack.push(737);
	listStack.push(0);
	for (MutantStack<int, std::list<int> >::iterator lit = listStack.begin(); lit != listStack.end(); ++lit)
		std::cout << *lit << std::endl;
	return 0;
}
