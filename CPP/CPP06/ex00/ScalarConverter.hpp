#pragma once
#include <iostream>
#include <string>
#include <iomanip>
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
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter operator=(const ScalarConverter& other);

		inputType detectType(const std::string& input);
		int stringToInt(const std::string& str);
		float stringToFloat(const std::string& str);
		double stringToDouble(const std::string& str);

		static void convert(const std::string& data);
};

