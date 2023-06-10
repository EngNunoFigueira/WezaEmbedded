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
#include <array>

void letterDistance(std::string firstLetter, std::string secondtLetter)
{
    int index{0};
    int distance{0};
    std::string diff{0};
    std::string iterator{0};
    if (firstLetter.length() >= secondtLetter.length()) {
        iterator = secondtLetter;
        diff     = firstLetter;
    }
    else {
        iterator = firstLetter;
        diff     = secondtLetter;
    }
    for (unsigned char letter : iterator)
    {
        distance += (int)abs(letter - static_cast<unsigned char>(diff[index]));
        index++;
    }

    distance += static_cast<int>((diff.length() - iterator.length()));
    std::cout << "The distance between " << firstLetter << " & " << secondtLetter << " is :" << distance << std::endl;
}

int main()
{
    std::cout << "Calculate the distance between two words" << std::endl;
    letterDistance("house", "fly");
    letterDistance("sharp", "sharq");
    letterDistance("abcde", "Abcde");
    letterDistance("abcde", "bcdef");

    return 0;
}

