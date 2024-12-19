#include "Serializer.hpp"

int	main()
{
	Data	GT3 = {.brand = "Porsche", \
				.model = "911 GT3", \
				.color = "Orange", \
				.fuel = "Gasoline", \
				.top_speed = 313, \
				.acceleration = 3.9, \
				.year = 2024};

	uintptr_t	value;
	Data		*GT3_replica;

	std::cout << "----- CAR SPECIFICATIONS -----" << std::endl;
	std::cout << "BRAND:" << GT3.brand << std::endl; 
	std::cout << "MODEL: " << GT3.model << std::endl;
	std::cout << "YEAR: " << GT3.year << std::endl;
	std::cout << "COLOR: " << GT3.color << std::endl;
	std::cout << "FUEL: " << GT3.fuel << std::endl;
	std::cout << "TOP_SPEED: " << GT3.top_speed << std::endl;
	std::cout << "ACCELERATION: " << GT3.acceleration << std::endl;

	value = Serializer::serialize(&GT3);
	GT3_replica = Serializer::deserialize(value);

	std::cout << std::endl << "----- REPLICA SPECIFICATIONS -----" << std::endl;
	std::cout << "BRAND:" << GT3_replica->brand << std::endl; 
	std::cout << "MODEL: " << GT3_replica->model << std::endl;
	std::cout << "YEAR: " << GT3_replica->year << std::endl;
	std::cout << "COLOR: " << GT3_replica->color << std::endl;
	std::cout << "FUEL: " << GT3_replica->fuel << std::endl;
	std::cout << "TOP_SPEED: " << GT3_replica->top_speed << std::endl;
	std::cout << "ACCELERATION: " << GT3_replica->acceleration << std::endl << std::endl;

	std::cout << "Original = " << &GT3 << std::endl;
	std::cout << "Replica = " << GT3_replica << std::endl;
}