#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &rhs)
{
	(void)rhs;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data *raw)
{
	return (reinterpret_cast<uintptr_t>(raw));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

