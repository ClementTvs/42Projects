#include "iter.hpp"
#include <iostream>

template <typename T>
void printArray(const T& tpl){
	std::cout << tpl << std::endl;
}

int main(){
	int i[3] = {3, 4, 5};
	char c[3] = {'a', 'b', 'c'};

	::iter(i, 3, printArray);
	::iter(c, 3, printArray);
}