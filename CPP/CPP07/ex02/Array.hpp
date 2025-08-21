#ifndef ARRAY_HPP 
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	private:
		T* data;
		unsigned int length;
	
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);

		T& operator[](unsigned int i);
		unsigned int size() const;

		class IndexOutOfBonds: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Index out of bounds";
				}
		};
};

#include "Array.tpp"
#endif