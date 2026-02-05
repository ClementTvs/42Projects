#include "RPN.hpp"

int main(int ac, char **av) {
    RPN rpn;
    int res;
    if (ac != 2) {
        std::cerr << "Error: Please use like this -> ./RPN \"3 4 + 5 -\" ." << std::endl;
        return 1;
    }
    char* s = av[1];
    std::string input(s);

    try {
        res = rpn.processRPN(input);
        std::cout << res << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}