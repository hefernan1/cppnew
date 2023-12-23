#include "Serializer.hpp"

int main() 
{
	Data		*data = new Data();
	
	uintptr_t	serializeData;
	Data		*deserializeData;

	data->x = '5';
	data->y = '6';


	std::cout << "Data" << std::endl;
	std::cout << data << std::endl << std::endl;

	std::cout << "Serialized Data" << std::endl;
	serializeData = Serializer::serialize(data);
	std::cout << "0x" << std::hex << serializeData << std::endl << std::endl;

	std::cout << "Deserialized Data" << std::endl;
	deserializeData = Serializer::deserialize(serializeData);
	std::cout << deserializeData << std::endl;
	std::cout << "x | y : " << deserializeData->x << " | " << deserializeData->y << std::endl << std::endl;
	
	delete data;
}