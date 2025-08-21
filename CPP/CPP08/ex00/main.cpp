#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>


int main() {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	l.push_back(1);
	l.push_back(6);
	l.push_back(3);
	d.push_back(1);
	d.push_front(6);
	d.push_back(7);
	try {
		std::cout << easyfind(v, 1) << std::endl;
	} catch (const NothingFound& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << easyfind(l, 3) << std::endl;
	} catch (const NothingFound& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << easyfind(d, 7) << std::endl;
	} catch (const NothingFound& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}