//
// Created by rdas-nev on 4/4/23.
//

#include "../inc/Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->data1 = 1;
	data->data2 = 2;
	Serializer::deserialize(Serializer::serialize(data));
	std::cout << "data1: " << data->data1 << std::endl;
	std::cout << "data2: " << data->data2 << std::endl;
	delete data;
	return 0;
}
