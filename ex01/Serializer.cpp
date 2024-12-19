#include "Serializer.hpp"

// CONSTRUCTORS & DESTRUCTORS

Serializer::Serializer()
{
	//std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(const Serializer &copy)
{
	//std::cout << "Serializer copy constructor called\n";
	*this = copy;
}

Serializer::~Serializer()
{
	//std::cout << "Serializer default destructor called\n";
}

// OPERATORS

Serializer&	Serializer::operator=(const Serializer &copy)
{
	//std::cout << "Serializer copy assignment operator called\n";
	(void)copy;
	return (*this);
}

// MEMBER FUNCTIONS

// It takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// It takes an unsigned integer parameter and converts it to a pointer to Data
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}