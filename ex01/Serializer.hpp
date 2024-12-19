#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>
# include "Data.hpp"


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &a);
		~Serializer() ;
		Serializer&	operator=(const Serializer &copy);
		
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

std::ostream	&operator<<(std::ostream &stream, const Serializer &right);

#endif