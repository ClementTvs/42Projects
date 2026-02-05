#pragma once

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
    private:
        std::stack<int> stack;

    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        int processRPN(std::string &input);
};