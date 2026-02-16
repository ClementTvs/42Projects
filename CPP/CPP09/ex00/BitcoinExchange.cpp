#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_rates = other._rates;
 }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_rates = other._rates;
    }
    return *this;
}

std::string BitcoinExchange::trim(const std::string& line) {
    size_t start = line.find_first_not_of(" \t");
    size_t end = line.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return line.substr(start, end - start + 1);
}

bool BitcoinExchange::splitLine(const std::string& line, std::string& date, std::string& value) {
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        return false;
    date = trim(line.substr(0, pos));
    value = trim(line.substr(pos + 1));
    return true;
}

bool BitcoinExchange::isDateValid(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12)
        return false;

    int dayInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && leap)
        dayInMonth[1] = 29;

    if (day < 1 || day > dayInMonth[month - 1])
        return false;

    if (year == 2009 && month == 1 && day < 3)
        return false;

    return true;
}


bool BitcoinExchange::isValueValid(const std::string& valueStr, float& value) {
    char* end;
    value = std::strtof(valueStr.c_str(), &end);

    if (*end != '\0')
        return false;

    if (value < 0)
        return false;
    if (value > 1000)
        return false;    

    return true;
}

float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it;

    it = _rates.lower_bound(date);

    if (it == _rates.end()) {
        --it;
    }
    else if (it->first != date) {
        if (it == _rates.begin())
            throw std::runtime_error("Error: No rate available");
        --it;
    }

    return it->second;
}


void BitcoinExchange::parseLine(const std::string& line) {
    std::string date, valueStr;
    float value;
    
    if (!splitLine(line, date, valueStr)) {
        PRINT_ERROR("bad input => " + line);
        return ;
    }
    if (!isDateValid(date)) {
        PRINT_ERROR("bad input => " + date);
        return ;
    }
    if (!isValueValid(valueStr, value)) {
        PRINT_ERROR("bad input => " + valueStr);
        return ;
    }

    try {
        float rate = getRateForDate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    } catch (std::exception& e) {
        PRINT_ERROR(e.what());
    }
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::string date;
        float rate;

        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> rate;

        _rates[date] = rate;
    }
}
