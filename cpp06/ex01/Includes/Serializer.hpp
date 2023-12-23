#pragma once

#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer 
{
	private :
		Serializer(); // constructor prive pour rendre la class non initiable
	public :
	
		//Serializer();
		Serializer(Serializer &obj);
		virtual ~Serializer();

		Serializer	&operator=(Serializer &rhs);

		static uintptr_t serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);

};