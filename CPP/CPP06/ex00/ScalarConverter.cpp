#include "ScalarConverter.hpp"

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

ScalarConverter ScalarConverter::operator=(const ScalarConverter& other){
	LOG_DEBUG("ScalarConverter assignment operator called");
	(void)other;
	if (this != &other)
	{}
	return *this;
}

inputType ScalarConverter::detectType(const std::string& input){
	bool hasPoint = false;

	if (input.length() == 1 && !isdigit(input[0])){
		return CHAR_TYPE;
	}
	if (input == "nan")
		return NAN_TYPE;
	for (size_t i = 0; i < input.length(); i++){
		if ((input[0] == '-' || input[0] == '+') && i == 0)
			i++;
		char c = input[i];
		if (c == '.')
		{
			if (i != input.length() - 1)
				hasPoint = true;
			else
				return INVALID_INPUT;
		}
		else if (!isdigit(c)){
			if (c == 'f' && i == input.length() - 1 && hasPoint)
				return FLOAT_TYPE;
			else
			{
				return INVALID_INPUT;
			}
		}
	}
	if (hasPoint)
		return DOUBLE_TYPE;
	return INT_TYPE;
}

int ScalarConverter::stringToInt(const std::string& str){
	std::stringstream sstr(str);
	int value = 0;
	sstr >> value;
	return value;
}

float ScalarConverter::stringToFloat(const std::string& str){
	std::stringstream sstr(str);
	float value = 0.0f;
	sstr >> value;
	return value;
}

double ScalarConverter::stringToDouble(const std::string& str){
	std::stringstream sstr(str);
	double value = 0.0;
	sstr >> value;
	return value;
}

void ScalarConverter::convert(const std::string& data){
	ScalarConverter converter;
	if (converter.detectType(data) == CHAR_TYPE) {
		char c;
		
		c = data[0];
		std::cout << c << std::endl;
	}
	else if (converter.detectType(data) == FLOAT_TYPE) {
		float f;

		f = converter.stringToFloat(data);
		std::cout << f << "f" << std::endl;
	}
	else if (converter.detectType(data) == INT_TYPE) {
		int i;

		i = converter.stringToInt(data);
		std::cout << i << std::endl;
	}
	else if (converter.detectType(data) == DOUBLE_TYPE) {
		double d;

		d = converter.stringToDouble(data);
		std::cout << d << std::endl;
	}
	else if (converter.detectType(data) == NAN_TYPE) {
		std::cout << "nan detected" << std::endl;
	}
	else
	{
		std::cout << "Error, please enter a valid input" << std::endl;
	}
	return ;
}