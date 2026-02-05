#include "BitcoinExchange.hpp"
#include <fstream>


int main(int ac, char **av) {
    if (ac != 2) {
        PRINT_ERROR("Error: Please, insert a txt file. Program must be used like this : ./btc input.txt");
        return 1;
    }
    std::ifstream input(av[1]);
    if (!input.is_open()) {
        PRINT_ERROR("Error: Can't open file!");
        return 1;
    }

    BitcoinExchange btc;
    std::string line;
    std::getline(input, line);
    while(std::getline(input, line)) {
        btc.parseLine(line);
    }
}