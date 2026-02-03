#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>

ScalarConverter::ScalarConverter(){
	LOG_DEBUG("ScalarConverter default constructor called");
}

ScalarConverter::~ScalarConverter(){
	LOG_DEBUG("ScalarConverter destructor called");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	LOG_DEBUG("ScalarConverter copy constructor called");
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	LOG_DEBUG("ScalarConverter assignment operator called");
	(void)other;
	return *this;
}

static inputType detectType(const std::string& input){
	if (input.empty())
		return INVALID_INPUT;

	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR_TYPE;

	if (input == "nan" || input == "-inf" || input == "+inf"
		|| input == "-inff" || input == "+inff" || input == "nanf")
		return NAN_TYPE;

	bool hasPoint = false;
	bool hasDigit = false;
	size_t start = 0;

	if (input[0] == '-' || input[0] == '+')
		start = 1;
	if (start >= input.length())
		return INVALID_INPUT;

	for (size_t i = start; i < input.length(); i++){
		char c = input[i];
		if (c == '.'){
			if (hasPoint || i == input.length() - 1)
				return INVALID_INPUT;
			hasPoint = true;
		}
		else if (isdigit(c)){
			hasDigit = true;
		}
		else{
			if (c == 'f' && i == input.length() - 1 && hasPoint && hasDigit)
				return FLOAT_TYPE;
			return INVALID_INPUT;
		}
	}
	if (!hasDigit)
		return INVALID_INPUT;
	if (hasPoint)
		return DOUBLE_TYPE;
	return INT_TYPE;
}

static double stringToDouble(const std::string& str){
	std::stringstream sstr(str);
	double value = 0.0;
	sstr >> value;
	return value;
}

static void printChar(double d){
	if (d < 0 || d > 127 || d != static_cast<int>(d))
		std::cout << "char : impossible" << std::endl;
	else if (!isprint(static_cast<int>(d)))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(static_cast<int>(d)) << "'" << std::endl;
}

static void printInt(double d){
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d){
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
}

static void printDouble(double d){
	std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
}

void ScalarConverter::convert(const std::string& data){
	inputType type = detectType(data);

	if (type == INVALID_INPUT){
		std::cout << "Error, please enter a valid input" << std::endl;
		return;
	}

	if (type == NAN_TYPE){
		SpecialFloat specials[] = {
			{"nanf", "nanf", "nan"},
			{"nan",  "nanf", "nan"},
			{"+inff", "+inff", "+inf"},
			{"-inff", "-inff", "-inf"},
			{"+inf", "+inff", "+inf"},
			{"-inf", "-inff", "-inf"}
		};
		for (int i = 0; i < 6; ++i){
			if (data == specials[i].input){
				std::cout << "char : impossible" << std::endl;
				std::cout << "int : impossible" << std::endl;
				std::cout << "float : " << specials[i].floatStr << std::endl;
				std::cout << "double : " << specials[i].doubleStr << std::endl;
				return;
			}
		}
	}

	double d;
	if (type == CHAR_TYPE)
		d = static_cast<double>(data[0]);
	else
		d = stringToDouble(data);

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
