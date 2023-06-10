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

void multipCaracterPrint(std::string && original)
{
    int nTimesToPrintChar{0};
    int strCharIndex{0};
    std::string stdChar{};
    std::string strNumber{""};
    int multiFactor {0};
    std::string output{};
    std::stringstream reverse{};
    while (original.length() > strCharIndex)
    {
        strNumber = original[strCharIndex + 1];
        nTimesToPrintChar = atoi( strNumber.c_str());
        for (int i {0}; i < nTimesToPrintChar; i++)
        {
            std::cout << original[strCharIndex];
        }
        strCharIndex += 2;
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    std::cout << "The exercise received a input parameter and we need to create the function" << std::endl;
    multipCaracterPrint("A1B2C3D4");
    multipCaracterPrint("A4B5C2");
    multipCaracterPrint("C2F1E5");
    multipCaracterPrint("T4S2V2");
    return 0;
}
