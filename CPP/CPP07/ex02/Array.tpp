template <typename T>
Array<T>::Array() : length(0) {
	data = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): length(n) {
	data = new T[n];
}

template <typename T>
Array<T>::~Array(){
	delete[] data;
}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length){
	data = new T[length];
	for (unsigned int i = 0; i < length; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
	if (this != &other) {
		delete[] data;
		length = other.length;
		data = new T[length];
		for (unsigned int i = 0; i < length; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i){
	if (i >= length)
		throw IndexOutOfBonds();
	return data[i];
}

template <typename T>
unsigned int Array<T>::size() const{
	return length;
}