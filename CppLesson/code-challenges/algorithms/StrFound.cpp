#include <algorithm>
#include <array>
#include <iostream>
#include <stdio.h>
#include <vector>

struct node {
  int value;
  node *next = nullptr;
};

template <typename U> U functSum(U a, U b) { return a + b; }

using namespace std;

std::vector<int> getFoundStr(const std::string &str1, const std::string &str2) {

  int len = str1.length();
  std::string currStr{};
  std::vector<int> postionsFound{-1};

  if ((!str1.empty()) && (!str2.empty()) && (str1.length() > str2.length())) {
    std::string strAux = str1;

    for (int i{0}; i < len; i++) {
      currStr = strAux.erase(i, 1);
      std::cout << "The currStr is:" << currStr << std::endl;

      if (currStr.compare(str2) == 0) {
        postionsFound.push_back(i);
      }

      strAux = str1;
      std::cout << "The strAux is:" << strAux << std::endl;
    }
  }

  return postionsFound;
}

void reverseStr(std::string str) {
  std::string aux{};
  int len = str.length();

  if (!str.empty()) {
    for (int i{len}; i > 0; i--) {
      std::cout << str[i] << std::endl;
    }
  } else {
    std::cout << "You should pass a no empty string" << std::endl;
  }
}

void sortArrayNumbers(std::array<int, 5> numbers) {
  int len = numbers.size();
  for (int i{0}; i < len - i; i++) {
    for (int j{0}; j < len - j - 1; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int aux = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = aux;
      }
    }
  }
}

int main(int argc, char **argv) {

  std::string str1{"Holanda"};
  std::string str2{"Hlanda"};

  std::cout << "This is an exercise for training algorithm." << std::endl;

  std::vector<int> results = getFoundStr(str1, str2);

  reverseStr("mamatuti");
  /*
   for(int value : results)
    {
       std::cout << "Found coincidence at Pos: " << value<< std::endl;
    }

    std::cout << "The result is " << results.size()<< std::endl;
  */

  return 0;
}