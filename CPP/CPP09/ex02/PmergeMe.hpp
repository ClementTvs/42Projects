#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

class PMergeMe {
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    double _vectorTime;
    double _dequeTime;
    
    int convertToInt(const std::string& str);
    std::vector<int> generateJacobsthalSequence(int n);
    std::vector<int> generateInsertionOrder(int n);
    
    int binarySearchVector(const std::vector<int>& sorted, int value, int right);
    void fordJohnsonVector(std::vector<int>& arr);
    
    int binarySearchDeque(const std::deque<int>& sorted, int value, int right);
    void fordJohnsonDeque(std::deque<int>& arr);

    std::vector<std::string> split(char *str);
    bool hasSpace(char *str);
    bool hasDouble(const std::vector<int>& vector);

public:
    PMergeMe();
    ~PMergeMe();
    
    bool checkArgs(int ac, char **av);
    void sort();
    void printBefore();
    void printResults();
};