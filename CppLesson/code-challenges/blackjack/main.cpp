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

bool isBlackjak(char *playerCards, int numberOfCards)
{
    int values{0};
    char readCardPoint{};

    for (int hand{0}; hand < numberOfCards;  hand++)
    {
        readCardPoint = *(playerCards + hand);
        switch (readCardPoint)
        {
        case  '1':
            values = values + 1;
            break;
        case  '2':
            values = values + 2;
            break;
        case  '3':
            values = values + 3;
            break;
        case  '4':
            values = values + 4;
            break;
        case  '5':
            values = values + 5;
            break;
        case  '6':
            values = values + 6;
            break;
        case  '7':
            values = values + 7;
            break;
        case  '8':
            values = values + 8;
            break;
        case  '9':
            values = values + 9;
            break;
        case  'J':
            values = values + 10;
            break;
        case  'K':
            values = values + 10;
            break;
        case  'Q':
            values = values + 10;
            break;
        case  'A':
            values = values + 11;
            break;
        default:
            break;
        }
    }

    return values <= 21 ? false : true;
}

int main()
{
    std::cout << "The exercise received a matrix and transpose their values" << std::endl;
    char game1[3] = {'2', '8', 'J'};
    char game2[3] = {'1', '8', 'J'};
    char game3[3] = {'A', 'J', 'K'};
    char game6[4] = {'J', 'Q', 'K'};
    char game4[4] = {'5', '5', '3', '9'};
    char game5[5] = {'2', '6', '4', '4', '5'};
    isBlackjak(game1,3) ? std::cout << "congratulations you have a BLACKJACK"<< std::endl : std::cout << "sorry do you don't have enough luck this time" << std::endl;
    isBlackjak(game2,3) ? std::cout << "congratulations you have a BLACKJACK"<< std::endl : std::cout << "sorry do you don't have enough luck this time" << std::endl;
    isBlackjak(game3,3) ? std::cout << "congratulations you have a BLACKJACK"<< std::endl : std::cout << "sorry do you don't have enough luck this time" << std::endl;
    isBlackjak(game4,4) ? std::cout << "congratulations you have a BLACKJACK"<< std::endl : std::cout << "sorry do you don't have enough luck this time" << std::endl;
    isBlackjak(game5,5) ? std::cout << "congratulations you have a BLACKJACK"<< std::endl : std::cout << "sorry do you don't have enough luck this time" << std::endl;
    isBlackjak(game6,4) ? std::cout << "congratulations you have a BLACKJACK"<< std::endl : std::cout << "sorry do you don't have enough luck this time" << std::endl;

    return 0;
}
