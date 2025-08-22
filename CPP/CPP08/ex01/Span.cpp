#include "Span.hpp"

Span::Span() : size(0), numbers(0) {}
	
Span::~Span() {}
	
	
Span::Span(unsigned int N) : size(N), numbers(0) {}
	
	
Span::Span(const Span& other) : size(other.size), numbers(other.numbers) {}


Span& Span::operator=(const Span& other) {
	if (this != &other) {
		size = other.size;
		numbers = other.numbers;
	}
	return *this;
}

void Span::addNumber(unsigned int nb) {
	if (this->size != numbers.size()) {
		numbers.push_back(nb);
	}
	else
		throw SpanIsFull();
}

int Span::longestSpan() {
	int min = *numbers.begin();
	int max = *numbers.begin();
	
	if (numbers.size() > 1) {
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
			if (*it < min)
				min = *it;
			else if (*it > max)
				max = *it;
		}
	}
	else 
		throw NoSpanFound();
	return (max - min);
}

int Span::shortestSpan() {
	int shortestSpan = INT_MAX;
	
	if (numbers.size() > 1) {
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
			for (std::vector<int>::iterator it2 = numbers.begin(); it2 != numbers.end(); ++it2)
			{
				if (*it - *it2 < shortestSpan && *it > *it2)
					shortestSpan = *it - *it2;
				else if (*it2 - *it < shortestSpan && *it2 > *it)
					shortestSpan = *it2 - *it;
			}
		}
	}
	else 
		throw NoSpanFound();
	return (shortestSpan);
}