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
	else if (literal == "-inff" || literal == "-inf" \
	|| literal == "+inff" || literal == "+inf")
		infiniteConversion(literal);
}

bool	ScalarConverter::isNumber(std::string literal)
{
	int		dot_count = 0;
	size_t	i = 0;

	if (literal[0] != '-' && literal[0] != '+' && !isdigit(literal[0]))
		return (0);
	while (i < literal.length() - 1)
	{
		if (literal[i] == '.')
		{
			dot_count++;
			if (dot_count == 2 || !isdigit(literal[i + 1]))
				return (0);
		}
		else if (!isdigit(literal[i]))
			return (0);
		i++;
	}
	if (!(dot_count && literal[i] == 'f') && !isdigit(literal[i]))
		return (0);
	return (1);
}

void	ScalarConverter::charConversion(std::string literal)
{
	std::cout << literal << " IS CHAR!\n";

	char conversion = literal[0];
	if (!isprint(conversion))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << conversion << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "Float: " << static_cast<float>(conversion) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(conversion) << ".0" << std::endl;
}

void	ScalarConverter::intConversion(std::string literal)
{
	std::cout << literal << " IS INT!\n";
	
	int conversion = atoi(literal.c_str());
	if (!isprint(conversion))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << static_cast<char>(conversion) << "'" << std::endl;
	std::cout << "Int: " << conversion << std::endl;
	std::cout << "Float: " << static_cast<float>(conversion) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(conversion) << ".0" << std::endl;
}

void	ScalarConverter::floatConversion(std::string literal)
{
	std::cout << literal << " IS FLOAT!\n";
	
	float conversion = atof(literal.c_str());
	if (!isprint(conversion))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << static_cast<char>(conversion) << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "Float: " << conversion << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(conversion) << std::endl;
}

void	ScalarConverter::doubleConversion(std::string literal)
{
	std::cout << literal << " IS DOUBLE!\n";

	double conversion = atof(literal.c_str());
	if (!isprint(conversion))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << static_cast<char>(conversion) << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "Float: " << static_cast<float>(conversion) << "f" << std::endl;
	std::cout << "Double: " << conversion << std::endl;
}

void	ScalarConverter::infiniteConversion(std::string literal)
{
	std::cout << literal << " IS INFINITE!\n";

	//std::cout << "Char: " << static_cast<char>(conversion) << std::endl;
	//std::cout << "Int: " << static_cast<int>(conversion) << std::endl;
	//std::cout << "Float: " << static_cast<float>(conversion) << std::endl;
	//std::cout << "Double: " << static_cast<double>(conversion) << std::endl;
}