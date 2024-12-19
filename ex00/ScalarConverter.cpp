#include "ScalarConverter.hpp"

// CONSTRUCTORS & DESTRUCTORS

ScalarConverter::ScalarConverter()
{
	//std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	//std::cout << "ScalarConverter copy constructor called\n";
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter default destructor called\n";
}

// OPERATORS

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &copy)
{
	//std::cout << "ScalarConverter copy assignment operator called\n";
	(void)copy;
	return (*this);
}

// MEMBER FUNCTIONS

// Calls the correct converter for the string literal recieved
void	ScalarConverter::convert(std::string literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		charConversion(literal);
	else if (isNumber(literal))
	{
		if (literal.find(".") != literal.npos)
		{
			if (literal.find("f") != literal.npos)
				floatConversion(literal);
			else
				doubleConversion(literal);
		}
		else
			intConversion(literal);
	}
	else if (literal == "-inff" || literal == "-inf" || literal == "nanf" \
	|| literal == "+inff" || literal == "+inf" || literal == "nan")
		literalConversion(literal);
	else
		std::cerr << "Error: The string literal does not represent any valid scalar type" << std::endl;
}

// Checks if the string recieved is a number
bool	ScalarConverter::isNumber(std::string literal)
{
	int		dot_count = 0;
	size_t	i = 1;

	if (literal[0] != '-' && literal[0] != '+' && !isdigit(literal[0]))
		return (false);
	if (literal.length() == 1)
		return (true);
	while (i < literal.length() - 1)
	{
		if (literal[i] == '.')
		{
			dot_count++;
			if (dot_count == 2 || !isdigit(literal[i - 1]) || !isdigit(literal[i + 1]))
				return (false);
		}
		else if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	if (!(dot_count && literal[i] == 'f') && !isdigit(literal[i]))
		return (false);
	return (true);
}

// Checks if its possible to print a Char
bool	ScalarConverter::isPrintableChar(int conversion)
{
	if (conversion < std::numeric_limits<char>::min() || conversion > std::numeric_limits<char>::max())
	{
		std::cout << "Char: Impossible" << std::endl;
		return (false);
	}
	if (!isprint(static_cast<char>(conversion)))
	{
		std::cout << "Char: Non displayable" << std::endl;
		return (false);
	}
	return (true);
}

// Checks if its possible to print an Int
bool	ScalarConverter::isPossibleInt(long conversion)
{
	if (conversion < std::numeric_limits<int>::min() || conversion > std::numeric_limits<int>::max())
	{
		std::cout << "Int: Impossible" << std::endl;
		return (false);
	}
	return (true);
}

// Converts a string literal to char and displays it to char, int, float and double using cast
void	ScalarConverter::charConversion(std::string literal)
{
	char conversion = literal[0];

	if (isPrintableChar(conversion))
		std::cout << "Char: '" << conversion << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(conversion) << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(conversion) << std::endl;
}

// Converts a string literal to int and displays it to char, int, float and double using cast
void	ScalarConverter::intConversion(std::string literal)
{
	long pre_conversion = strtol(literal.c_str(), NULL, 10);
	if (pre_conversion < std::numeric_limits<int>::min() || pre_conversion > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: the int given overflows" << std::endl;
		return;
	}

	int conversion = atoi(literal.c_str());
	if (isPrintableChar(conversion))
		std::cout << "Char: '" << static_cast<char>(conversion) << "'" << std::endl;
	std::cout << "Int: " << conversion << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(conversion) << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(conversion) << std::endl;
}

// Converts a string literal to float and displays it to char, int, float and double using cast
void	ScalarConverter::floatConversion(std::string literal)
{
	float conversion = strtof(literal.c_str(), NULL);

	if (conversion < -std::numeric_limits<float>::max() || conversion > std::numeric_limits<float>::max())
	{
		std::cerr << "Error: the float given overflows" << std::endl;
		return;
	}

	if (isPrintableChar(conversion))
		std::cout << "Char: '" << static_cast<char>(conversion) << "'" << std::endl;
	if (isPossibleInt(conversion))
		std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << conversion << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(conversion) << std::endl;
}

// Converts a string literal to double and displays it to char, int, float and double using cast
void	ScalarConverter::doubleConversion(std::string literal)
{
	double conversion = strtod(literal.c_str(), NULL);

	if (conversion < -std::numeric_limits<double>::max() || conversion > std::numeric_limits<double>::max())
	{
		std::cerr << "Error: the double given overflows" << std::endl;
		return;
	}

	if (isPrintableChar(conversion))
		std::cout << "Char: '" << static_cast<char>(conversion) << "'" << std::endl;
	if (isPossibleInt(conversion))
		std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(conversion) << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << conversion << std::endl;
}

// Displays a pseudo literal to char, int, float
void	ScalarConverter::literalConversion(std::string literal)
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: " << static_cast<float>(strtof(literal.c_str(), NULL)) << "f" << std::endl;
	std::cout << "Double: " << static_cast<float>(strtof(literal.c_str(), NULL)) << std::endl;
}