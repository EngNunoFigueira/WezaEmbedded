/**
 * Date: 06/2024/
 * Autor: Nuno Figueira
 * Email: ekumbi48172@hotmail.com
 * Project: IT job Code Challenge
 * Video CV:  https://www.youtube.com/watch?v=liOPojIVjH4
 * LinkedInd: https://www.linkedin.com/in/nuno-figueira-2aa2785b/
 *
 * Editor Sublime
 * Programming language cpp version 11
 * Operation System Linux Ubuntu 20.04 LTS
 * Command line execution: ./main "input integer number" or ./main
 */

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>

using namespace std;
using boost::multiprecision::cpp_int;

/**
 * The method receive a signed integer and calculate the factorial.
 * But the Max size of type integer in C++ 11 standard is long long int, that
 * only support the factorial for n <= 65. To avoid the overflow for n >= 65, we
 * use the Boost library to support very large numbers computation.
 *
 * @param integer.
 * @return cpp_int
 */
const cpp_int calculateTheFatorial(const int nValue) {
  static cpp_int nFactorial{nValue};

  if (nValue == 1 || nValue == 2) {
    return nValue;
  }

  nFactorial = nFactorial * (nValue - 1);
  if ((nValue - 1) != 1)
    calculateTheFatorial((nValue - 1));

  return nFactorial;
}

int main(int argc, char **argv) {

  std::cout << "The factorial is ";
  argc == 1 ? std::cout << calculateTheFatorial(1) << std::endl
            : std::cout << calculateTheFatorial(atoi(argv[1])) << std::endl;

  return 0;
}
