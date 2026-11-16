#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) {}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();

	identify(obj1);
	identify(*obj2);
	identify(obj3);

	delete obj1;
	delete obj2;
	delete obj3;

	return 0;
}
