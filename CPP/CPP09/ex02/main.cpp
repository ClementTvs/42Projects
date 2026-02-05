#include "PmergeMe.hpp"

int main(int ac, char **av) { 
    if (ac <= 1) {
        std::cerr << "Usage: ./PmergeMe [positive integers]" << std::endl;
        return 1;
    }
    
    PMergeMe pmergeme;
    
    if (!pmergeme.checkArgs(ac, av))
        return 1;
    
    pmergeme.printBefore();
    pmergeme.sort();
    pmergeme.printResults();
    
    return 0;
}