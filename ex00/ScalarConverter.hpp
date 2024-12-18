#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <stdio.h>
# include <stdlib.h>
# include <cctype>
# include <iostream>
# include <string.h>
# include <fstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);

		static bool	isNumber(std::string literal);
		static void	charConversion(std::string literal);
		static void	intConversion(std::string literal);
		static void	floatConversion(std::string literal);
		static void	doubleConversion(std::string literal);
		static void	infiniteConversion(std::string literal);
		
	public:
		~ScalarConverter() ;
		ScalarConverter&	operator=(const ScalarConverter &copy);

		static void	convert(std::string literal);
};

std::ostream	&operator<<(std::ostream &stream, const ScalarConverter &right);

#endif