#include "Serializer.hpp"

Serializer::Serializer(){
	LOG_DEBUG("Serializer default constructor called");
}

Serializer::~Serializer(){
	LOG_DEBUG("Serializer destructor called")
}

Serializer::Serializer(const Serializer& other){
	LOG_DEBUG("Copy constructor called");
	(void)other;
}

Serializer &Serializer::operator=(const Serializer& other){
	LOG_DEBUG("Serializer assignement operator called");
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}