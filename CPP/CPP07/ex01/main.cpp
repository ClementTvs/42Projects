#include "iter.hpp"
#include <iostream>

template <typename T>
void printArrayConst(const T& tpl){
	std::cout << tpl << std::endl;
}

template <typename T>
void printArray(T& tpl){
	std::cout << tpl << std::endl;
}

int main(){
	int i[3] = {3, 4, 5};
	char c[3] = {'a', 'b', 'c'};

	::iter(i, 3, printArray<int>);
	::iter(c, 3, printArrayConst<char>);
}