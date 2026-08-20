#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
# include <cstddef>

typedef struct s_Data Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	// no instantiation - private constructors
	private:
		Serializer(); // default constructor
		Serializer(const Serializer &rhs); // copy constructor
		Serializer & operator=(const Serializer &rhs); // assignment operator
		~Serializer();
};

#endif

/*
** A void pointer (void *) is a special type of 
** pointer that can point to any data type. 
*/
