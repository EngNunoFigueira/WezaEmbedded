#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <thread>
#include <future>
#include <utility>
#include <memory>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <initializer_list>
#include <cstddef>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <list>
#include <sstream>
#include <regex>

auto isPrime(int primeNumbers)
{
    int isPrime{0};
    int currentNumber{1};
    std::vector<int> foundedPrimeNumbers;
    bool isNotPrime = false;


    while (primeNumbers >= currentNumber)
    {
        if (currentNumber == 2 || currentNumber == 3 || currentNumber == 5 || currentNumber == 7 || currentNumber == 11 || currentNumber == 13)
        {
            isPrime++;
            foundedPrimeNumbers.push_back(currentNumber);
        }
        else if (currentNumber > 1)
        {
            for (int i{2}; i <= currentNumber; i ++)
            {
                std::cout << currentNumber << " not default" << std::endl;
                if ((isNotPrime == false) && (currentNumber % i) == 0 && (currentNumber != i))
                {
                    std::cout << currentNumber << " is not prime " << std::endl;
                    isNotPrime = true;
                    break;
                }
            }
            if (!isNotPrime) {
                isPrime++;
                foundedPrimeNumbers.push_back(currentNumber);
            }
        }

        currentNumber++;
        isNotPrime = false;
    }

    return std::make_pair(foundedPrimeNumbers, isPrime);
}

int main()
{
    std::cout << "This exercise create a function that finds how many prime numbers there are, up to the given integer." << std::endl;
    auto [values, totalPrimes] = isPrime(30);
    std::cout << "The total number of prime number inside a 30 is " << totalPrimes << std::endl;
    std::cout << "These are the prime numbers found: { ";
    for (int n : values)
    {
        std::cout << n << " ";
    }
    std::cout <<  " } " << std::endl;
    return 0;
}
