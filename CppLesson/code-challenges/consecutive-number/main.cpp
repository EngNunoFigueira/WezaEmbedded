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
#include <boost/program_options.hpp>

namespace po = boost::program_options;
// Arguments will be stored here
std::string input;
std::string output;
std::string trace;

void TRACE_DEBUG(std::string message) {
    if (trace == "enable")
        std::cout << message << std::endl;
}

bool isOrderConsecutive(int *numbers)
{
    int counter{0};
    while (counter < 5) {

        int value{0};
        int compValue{1000000};
        int minimumPosition {0};
        bool foundMinimum{false};

        TRACE_DEBUG("Check if the array elements can be ascending ordered");
        if ((counter == 2) && abs(numbers[1] - numbers[0] != 1)) {
            TRACE_DEBUG("This array is not consecutive");
            return false;
        }

        for ( int i{0 + counter}; i < 5; ++i )
        {
            if ( (numbers[i] < compValue) && (compValue != numbers[i]) )
            {
                value           = {std::move(compValue)};
                compValue       = numbers[i];
                minimumPosition = i;
                foundMinimum    = true;
            }
        }

        if ( (foundMinimum == true) && (minimumPosition != 0) ) {
            value = numbers[0 + counter];
            numbers[0 + counter] = compValue;
            numbers[minimumPosition] = value;
        }

        ++counter;
    }
    return true;
}

int  main(int argc, char** argv)
{
    TRACE_DEBUG("Configure options here");
    po::options_description desc ("Allowed options");
    desc.add_options ()
    ("help,h", "print usage message")
    ("trace,d", po::value(&trace), "Trace debug")
    ("input,i", po::value(&input), "Input file")
    ("output,o", po::value(&output), "Output file");
    // Parse command line arguments
    po::variables_map vm;
    po::store (po::command_line_parser (argc, argv).options (desc).run (), vm);
    po::notify (vm);
    // Check if there are enough args or if --help is given
    if (vm.count ("help") || !vm.count ("input") || !vm.count ("output") || !vm.count ("trace")) {
        std::cerr << desc << "\n";
        return 1;
    }

    std::cout << "Determine if the array elements are consecutives:" << std::endl;
    std::array<int, 5> _numbers{15, 14, 10, 10, 12};
    isOrderConsecutive(_numbers.data());

    return 0;
}



