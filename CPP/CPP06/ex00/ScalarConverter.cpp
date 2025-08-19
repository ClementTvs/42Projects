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
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff" || input == "nanf")
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
	char c;
	float f = 0.0f;
	int i = 0;
	double d = 0.0;
    SpecialFloat specials[] = {
        {"nanf", "nanf", "nan"},
        {"nan",  "nanf",  "nan"},
        {"+inff", "+inff", "+inf"},
        {"-inff", "-inff", "-inf"},
        {"+inf", "+inff", "+inf"},
        {"-inf", "-inff", "-inf"}
    };

	if (converter.detectType(data) == CHAR_TYPE) {
		c = data[0];
		f = static_cast<float>(c);
		i = static_cast<int>(c);
		d = static_cast<double>(c);

		std::cout << "char : '" << c << "'"<< std::endl;
		std::cout << "int : " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
	}
	else if (converter.detectType(data) == FLOAT_TYPE) {
		f = converter.stringToFloat(data);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);

		if (isprint(c))
			std::cout << "char : '" << c << "'"<< std::endl;
		else
			std::cout << "char : non displayable" << std::endl;
		std::cout << "int : " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
		std::cout << "double : " << d  << std::endl;
	}
	else if (converter.detectType(data) == INT_TYPE) {
		i = converter.stringToInt(data);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);

		if (isprint(c))
			std::cout << "char : '" << c << "'"<< std::endl;
		else
			std::cout << "char : non displayable" << std::endl;
		std::cout << "int : " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
		std::cout << "double : " << d  << std::endl;
	}
	else if (converter.detectType(data) == DOUBLE_TYPE) {
		d = converter.stringToDouble(data);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
		i = static_cast<int>(d);

		if (isprint(c))
			std::cout << "char : '" << c << "'"<< std::endl;
		else
			std::cout << "char : non displayable" << std::endl;
		std::cout << "int : " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
		std::cout << "double : " << d  << std::endl;
	}
	else if (converter.detectType(data) == NAN_TYPE) {
	    bool found = false;
	    for (int i = 0; i < 6; ++i) {
	        if (data == specials[i].input) {
	            found = true;
	            std::cout << "char : impossible" << std::endl;
	            std::cout << "int : impossible" << std::endl;
	            std::cout << "float : " << specials[i].floatStr << std::endl;
	            std::cout << "double : " << specials[i].doubleStr << std::endl;
	            break;
	        }
	    }
	}
	else
	{
		std::cout << "Error, please enter a valid input" << std::endl;
	}
	return ;
}