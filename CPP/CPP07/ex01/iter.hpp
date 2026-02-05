#ifndef _ITER_HPP_
#define _ITER_HPP_

template <typename T, typename F>
void iter(T* array, int n, F f)
{
	for (int i = 0; i < n; i++)
		f(array[i]);
}

#endif