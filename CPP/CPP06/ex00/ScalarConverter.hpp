#pragma once
#include <iostream>
#include <cctype>
#include <string>
#ifdef DEBUG
#define LOG_DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#define LOG_DEBUG(x)
#endif

enum inputType{ INT_TYPE, DOUBLE_TYPE, FLOAT_TYPE, CHAR_TYPE, INVALID_INPUT, NAN_TYPE};

class ScalarConverter{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter operator=(const ScalarConverter& other);

		inputType detectType(const std::string& input);

		static void convert(const std::string& data);
};