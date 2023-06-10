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

bool startCardGame(std::vector<int> && playerOne, std::vector<int> && playerTwo)
{
    std::sort(playerOne.begin(), playerOne.end());
    std::sort(playerTwo.begin(), playerTwo.end());
    unsigned long int indexOfMaxValue {playerOne.size() - 1};
    return (playerOne.at(indexOfMaxValue) + playerOne.at(indexOfMaxValue - 1)) > (playerTwo.at(indexOfMaxValue) + playerTwo.at(indexOfMaxValue - 1)) ? true : false;
}

bool startCardGame(std::vector<int> &playerOne, std::vector<int> & playerTwo)
{
    std::sort(playerOne.begin(), playerOne.end());
    std::sort(playerTwo.begin(), playerTwo.end());
    unsigned long int indexOfMaxValue {playerOne.size() - 1};
    return (playerOne.at(indexOfMaxValue) + playerOne.at(indexOfMaxValue - 1)) > (playerTwo.at(indexOfMaxValue) + playerTwo.at(indexOfMaxValue - 1)) ? true : false;
}

int main()
{
    std::cout << "Create a function that determines whether elements in an array can be re-arranged to form a consecutive list of numbers where each number appears exactly once." << std::endl;
    std::vector<int> playerOne{11, 13, 14, 15, 12};
    std::vector<int> playerTwo{21, 23, 24, 25, 22};
    //startCardGame(playerOne,playerTwo) == true ? std::cout << "playerOne win" << std::endl : std::cout << "playerTwo win" << std::endl;
    startCardGame({2, 5, 2, 6, 9}, {3, 7, 3, 1, 2}) == true ? std::cout << "player 1 win" << std::endl : std::cout << "player 2 win" << std::endl;
    startCardGame({1, 2, 3, 4, 5}, {9, 8, 7, 6, 5}) == true ? std::cout << "player 1 win" << std::endl : std::cout << "player 2 win" << std::endl;
    startCardGame({4, 3, 4, 4, 5}, {3, 2, 5, 4, 1}) == true ? std::cout << "player 1 win" << std::endl : std::cout << "player 2 win" << std::endl;

    return 0;
}
