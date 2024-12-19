#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <stdio.h>
# include <stdlib.h>
# include <cctype>
# include <iostream>
# include <string.h>
# include <fstream>
# include <limits>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		~ScalarConverter() ;
		ScalarConverter&	operator=(const ScalarConverter &copy);

		static bool	isNumber(std::string literal);
		static bool	isPrintableChar(int conversion);
		static bool	isPossibleInt(long conversion);
		static void	charConversion(std::string literal);
		static void	intConversion(std::string literal);
		static void	floatConversion(std::string literal);
		static void	doubleConversion(std::string literal);
		static void	literalConversion(std::string literal);
		
	public:
		static void	convert(std::string literal);
};

std::ostream	&operator<<(std::ostream &stream, const ScalarConverter &right);

#endif