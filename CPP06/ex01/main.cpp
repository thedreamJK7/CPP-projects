#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main( void )
{
	Data	*myData = new Data();

	myData->first = 42;
	myData->second = 84;

	uintptr_t temp = Serializer::serialize(myData);
	std::cout<< ">>>>>>>> Actual address(hex)! <<<<<<"<< std::endl;
	std::cout<< myData << std::endl;
	std::cout<< ">>>>>>>> Stored address(dec)! <<<<<<"<< std::endl;
	std::cout << temp << std::endl;
	Data *restored = NULL;
	restored = Serializer::deserialize (temp);

	std::cout<< ">>>>>>>> Address check! <<<<<<"<< std::endl;
	std::cout<< myData << std::endl;
	std::cout<< restored << std::endl;

	std::cout<< ">>>>>>>> Values check! <<<<<<"<< std::endl;
	std::cout<< restored->first << std::endl;
	std::cout<< restored->second << std::endl;
	return (0);
}
