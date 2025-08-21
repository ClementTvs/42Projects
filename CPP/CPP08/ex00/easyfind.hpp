#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>
#include <exception>

class NothingFound: public std::exception {
	public:
		virtual const char* what() const throw(){
			return "Int was not found in the container";
		}
};

template <typename T>
int easyfind(T& container, int i) {
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), i);
	if (it == container.end()){
		throw NothingFound();
	}
	return *it;
}

#endif