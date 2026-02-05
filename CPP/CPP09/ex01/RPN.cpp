#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    this->stack = other.stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->stack = other.stack;
    }
    return *this;
}

int RPN::processRPN(std::string& input) {
    std::stringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        int value;
        std::stringstream ss(token);

        if ((ss >> value) && ss.eof()) {
            if (value > 9)
                throw std::runtime_error("Error: Only number below 10 are allowed");
            stack.push(value);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: Incorrect input");
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(b + a);
            else if (token == "-")
                stack.push(b - a);
            else if (token == "*")
                stack.push(b * a);
            else if (token == "/") {
                if (a == 0)
                    throw std::runtime_error("Error: Can't divide by 0");
                stack.push(b / a);
            }
        }
        else
            throw std::runtime_error("Error: Only int, +, -, / and * are authorized");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid size in the stack after operation");
    return stack.top();
}