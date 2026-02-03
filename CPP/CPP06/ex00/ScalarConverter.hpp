#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <sstream>
#ifdef DEBUG
#define LOG_DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#define LOG_DEBUG(x)
#endif

enum inputType{ INT_TYPE, DOUBLE_TYPE, FLOAT_TYPE, CHAR_TYPE, INVALID_INPUT, NAN_TYPE};
struct SpecialFloat {
	std::string input;
	std::string floatStr;
	std::string doubleStr;
};


class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter operator=(const ScalarConverter& other);

	public:
		static void convert(const std::string& data);
};

