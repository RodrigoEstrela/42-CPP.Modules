//
// Created by rdas-nev on 4/4/23.
//

#include "../inc/Serializer.hpp"

// Orthodox Canonical Form =====================================================
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
}
// =============================================================================

// Convert pointer to uintptr_t ================================================
uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t uptr;
	uptr = reinterpret_cast<uintptr_t>(ptr);
	return (uptr);
}
// =============================================================================

// Convert uintptr_t to pointer ================================================
Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data_ptr;
	data_ptr = reinterpret_cast<Data*>(raw);
	return data_ptr;
}
// =============================================================================
