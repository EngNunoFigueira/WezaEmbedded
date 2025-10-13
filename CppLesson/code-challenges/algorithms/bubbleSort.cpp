#include <algorithm>
#include <array>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void sortArrayNumbers(std::array<int, 5> numbers) {
  int len = numbers.size();
  for (int i{0}; i < len - i; i++) {
    for (int j{0}; j < len - j - 1; j++) {
      if (numbers[j] < numbers[j + 1]) {
        int aux = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = aux;
      }
    }
  }

 std::cout<<"The is the sort output:"<<std::endl;
 for(int i{0}; i < len; i++)
 {
    std::cout<<numbers[i]<<std::endl;
 }

}


int main(int argc, char ** argv)
{
  std::array<int, 5> numbers {3,5,7,9,1};

  std::cout<<"This program implement the sort bubble algorithm..."<<std::endl;

  sortArrayNumbers(numbers);

  return 0;
}
