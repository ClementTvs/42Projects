#ifndef _WHATEVER_HPP_
#define _WHATEVER_HPP_

template <typename T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

template <typename T>
T min(T a, T b){
	if (a < b)
		return a;
	return b;
}

template <typename T>
void swap(T &a, T &b){
	T temp;

	temp = a;
	a = b;
	b = temp;
}

#endif