#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base 	*generate(void)
{
	static int	timer = time(0);
	std::srand(timer++);
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type of the object pointed to by p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type of the object pointed to by p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type of the object pointed to by p: C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type of the object pointed to by p: A" << std::endl;
	}
	catch(const std::exception& e){}

	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Type of the object pointed to by p: B" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Type of the object pointed to by p: C" << std::endl;
	}
	catch(const std::exception& e){}
}

int main ()
{
	Base* which;

	which = generate();
	identify(which);
	identify(*which);
	delete which;

	return (0);
}