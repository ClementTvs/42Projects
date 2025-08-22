#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <exception>
#include <vector>
#include <limits.h>

class Span {
	private:
		unsigned int size;
		std::vector<int> numbers;

	public:
		Span();
		~Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(unsigned int nb);
		int shortestSpan();
		int longestSpan();

	class SpanIsFull : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "The span is already full, can't add a new number";
			}
	};

	class NoSpanFound : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "There was no span found";
			}
	};

	template <typename It>
	void addRange(It first, It last) {
		for (It it = first; it != last; ++it) {
			addNumber(*it);
		}
	}
};

#endif