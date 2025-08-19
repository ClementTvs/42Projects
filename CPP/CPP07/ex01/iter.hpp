#ifndef _ITER_HPP_
#define _ITER_HPP_

template <typename T>
void iter(T* array, int n, void (*f)(const T&))
{
	for (int i = 0; i < n; i++)
		f(array[i]);
}

#endif