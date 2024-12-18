#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
	{
		std::cerr << "The Converter requires only one argument" << std::endl;
		return (2);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}