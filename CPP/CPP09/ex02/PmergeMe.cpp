#include "PmergeMe.hpp"
#include <iomanip>

PMergeMe::PMergeMe() : _vectorTime(0), _dequeTime(0) {}

PMergeMe::~PMergeMe() {}

int PMergeMe::convertToInt(const std::string& str) {
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);

    if (*end != '\0' || str.empty())
        return -1;

    if (val < 0 || val > INT_MAX)
        return -1;

    return static_cast<int>(val);
}

bool PMergeMe::hasSpace(char *str){
    std::string s(str);

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ')
        return true;
    }
    return false;
}

bool PMergeMe::checkArgs(int ac, char** av) {
    if (ac == 2 && hasSpace(av[1])) {
        std::vector<std::string> token = split(av[1]);
        for (size_t i = 0; i < token.size(); i++) {
            int val = convertToInt(token[i]);
            if (val == -1) {
                std::cerr << "Error -> " << token[i] << std::endl;
                return false;
            }
            _vector.push_back(val);
            _deque.push_back(val);
        }
    }
    else {
        for (int i = 1; i < ac; i++) {
            if (std::strlen(av[i]) == 0) {
                std::cerr << "Error -> empty string" << std::endl;
                return false;
            }
            int val = convertToInt(av[i]);
            if (val == -1) {
                std::cerr << "Error -> " << av[i] << std::endl;
                return false;
            }
            _vector.push_back(val);
            _deque.push_back(val);
        }
    }
    if (hasDouble(_vector)) {
        std::cerr << "Error: Have number in double" << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> PMergeMe::split(char *str) {
    std::vector<std::string> result;
    std::string s;
    
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (!s.empty()) {
                result.push_back(s);
                s.clear();
            }
        }
        else
            s += str[i];
    }
    if (!s.empty())
        result.push_back(s);
    
    return result;
}

bool PMergeMe::hasDouble(const std::vector<int>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        int val = vector[i];
        for (size_t j = 0; j < vector.size(); ++j) {
            if (j != i && vector[j] == val)
                return true;
        }
    }
    return false;
}


std::vector<int> PMergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<int> PMergeMe::generateInsertionOrder(int n) {
    if (n <= 0)
        return std::vector<int>();
    
    std::vector<int> order;
    std::vector<int> jacobsthal = generateJacobsthalSequence(n);
    
    order.push_back(1);
    
    for (size_t k = 2; k < jacobsthal.size(); ++k) {
        int start = jacobsthal[k];
        int end = jacobsthal[k - 1] + 1;
        
        if (start > n)
            start = n;
        
        for (int i = start; i >= end; --i) {
            if (std::find(order.begin(), order.end(), i) == order.end()) {
                order.push_back(i);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (std::find(order.begin(), order.end(), i) == order.end()) {
            order.push_back(i);
        }
    }
    
    return order;
}

int PMergeMe::binarySearchVector(const std::vector<int>& sorted, int value, int right) {
    int left = 0;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PMergeMe::fordJohnsonVector(std::vector<int>& arr) {
    if (arr.size() <= 1)
        return;
    
    if (arr.size() == 2) {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }
    
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    if (hasStraggler)
        straggler = arr[arr.size() - 1];
    
    std::vector<std::pair<int, size_t> > winnersWithIndex;
    for (size_t i = 0; i < pairs.size(); ++i)
        winnersWithIndex.push_back(std::make_pair(pairs[i].first, i));
    
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    
    fordJohnsonVector(winners);
    
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == winners[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    if (!sortedPairs.empty()) {
        mainChain.push_back(sortedPairs[0].second);
        for (size_t i = 0; i < sortedPairs.size(); ++i)
            mainChain.push_back(sortedPairs[i].first);
        
        for (size_t i = 1; i < sortedPairs.size(); ++i)
            pending.push_back(sortedPairs[i].second);
    }
    
    if (hasStraggler)
        pending.push_back(straggler);
    
    std::vector<int> insertionOrder = generateInsertionOrder(pending.size());
    
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int idx = insertionOrder[i] - 1;
        if (idx >= 0 && idx < static_cast<int>(pending.size())) {
            int value = pending[idx];
            int pos = binarySearchVector(mainChain, value, mainChain.size());
            mainChain.insert(mainChain.begin() + pos, value);
        }
    }
    
    arr = mainChain;
}


int PMergeMe::binarySearchDeque(const std::deque<int>& sorted, int value, int right) {
    int left = 0;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PMergeMe::fordJohnsonDeque(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return;
    
    if (arr.size() == 2) {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }
    
    std::deque<std::pair<int, int> > pairs;
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    if (hasStraggler)
        straggler = arr[arr.size() - 1];
    
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    
    fordJohnsonDeque(winners);
    
    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == winners[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    
    std::deque<int> mainChain;
    std::deque<int> pending;
    
    if (!sortedPairs.empty()) {
        mainChain.push_back(sortedPairs[0].second);
        for (size_t i = 0; i < sortedPairs.size(); ++i)
            mainChain.push_back(sortedPairs[i].first);
        
        for (size_t i = 1; i < sortedPairs.size(); ++i)
            pending.push_back(sortedPairs[i].second);
    }
    
    if (hasStraggler)
        pending.push_back(straggler);
    
    std::vector<int> insertionOrder = generateInsertionOrder(pending.size());
    
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int idx = insertionOrder[i] - 1;
        if (idx >= 0 && idx < static_cast<int>(pending.size())) {
            int value = pending[idx];
            int pos = binarySearchDeque(mainChain, value, mainChain.size());
            mainChain.insert(mainChain.begin() + pos, value);
        }
    }
    
    arr = mainChain;
}


void PMergeMe::printBefore() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i];
        if (i < _vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PMergeMe::sort() {
    clock_t start, end;
    
    start = clock();
    fordJohnsonVector(_vector);
    end = clock();
    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    start = clock();
    fordJohnsonDeque(_deque);
    end = clock();
    _dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PMergeMe::printResults() {
    std::cout << "After:  ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i];
        if (i < _vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << _dequeTime << " us" << std::endl;
}