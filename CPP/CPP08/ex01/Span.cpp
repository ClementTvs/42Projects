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

void Span::addNumber(int nb) {
	if (this->size != numbers.size()) {
		numbers.push_back(nb);
	}
	else
		throw SpanIsFull();
}

int Span::longestSpan() {
    if (numbers.size() <= 1)
        throw NoSpanFound();
    
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    
    return max - min;
}

int Span::shortestSpan() {
    if (numbers.size() <= 1)
        throw NoSpanFound();
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    
    return shortest;
}