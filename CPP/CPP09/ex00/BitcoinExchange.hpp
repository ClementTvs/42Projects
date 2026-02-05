#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <fstream>

#define PRINT_ERROR(x) std::cerr << x << std::endl

class BitcoinExchange {
    private:
        std::map<std::string, float> _rates;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        bool isDateValid(const std::string& date);
        bool isValueValid(const std::string& string, float& value);
        bool splitLine(const std::string& line, std::string& date, std::string& value);
        void parseLine(const std::string& line);
        std::string trim(const std::string& string);
        float getRateForDate(const std::string& date) const;
        void loadDatabase(const std::string& filename);
};
