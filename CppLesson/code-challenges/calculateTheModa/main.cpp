/**
 * Date: 06/2024/
 * Autor: Nuno Figueira
 * Email: ekumbi48172@hotmail.com
 * Project: IT job Interview Code Challenge
 * Video CV:  https://www.youtube.com/watch?v=liOPojIVjH4
 * LinkedInd: https://www.linkedin.com/in/nuno-figueira-2aa2785b/
 *
 * Editor Sublime
 * Programming language Cpp version 11
 * Operation System Linux Ubuntu 20.04 LTS
 * Command line execution: ./main "input number" or without input parameters
 * ./main
 */

#include <iostream>
#include <optional>
#include <string>

/**
 * The method receive an ordered array of integers and found the moda.
 * @param int
 * @param int
 * @return int
 */

std::optional<int *> calculateTheModa(int numbers[], const int &arrSize) {

  int beginIndex{0};
  int modaValue{0};
  int modaIndex{0};
  int currModaIndex{0};
  int currentModaSize{0};
  int lastIndex{arrSize / 2};

  while (beginIndex != lastIndex) {
    int counter{0};
    for (beginIndex; beginIndex != lastIndex; beginIndex++) {
      if (numbers[beginIndex] == numbers[beginIndex + 1]) {
        if (counter == 0) {
          currModaIndex = beginIndex + 1;
        }

        counter++;
      } else {
        counter = 0;
      }

      if (((counter > 0) && (currentModaSize == 0)) ||
          (counter > currentModaSize) ||
          ((modaValue < numbers[beginIndex + 1]) && (currentModaSize != 0) &&
           (counter == 1))) {

        currentModaSize = counter;
        modaIndex = currModaIndex;
        modaValue = numbers[modaIndex];
      }
    }

    if ((currentModaSize == (lastIndex - 1)))
      return &numbers[modaIndex];
    lastIndex = arrSize - 1;
  }

  return currentModaSize != 0 ? &numbers[modaIndex] : nullptr;
}

int main(int argc, char **argv) {

  /**
   * To testing the solution we use these arays listed below.
   * Where each array values was used for testing different scenaios, such as:
   *
   * 1- Minimize the Big On Notation. It happen when we can found the moda in
   * the middle of array. In this case the O(n/2) or the half size of array.
   *
   * 2 - In case of a couples of number has the same MODA or repetitions, we
   * return the MODA with max value.
   *
   * 3 - To cover the case when the input array does not has MODA or
   * repeted numbers, the function return an optional value.
   */
  int moda[21] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4,
                  4, 4, 5, 5, 5, 5, 5, 5, 5, 5};
  int modaB[12] = {1, 2, 2, 2, 3, 4, 5, 6, 6, 7, 7, 7};
  int modaC[15] = {1,  12,  12,  12,  32,  32,   38,   72,
                   94, 105, 206, 360, 917, 1017, 17091};
  int modaD[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto getModa = calculateTheModa(modaD, 10);
  getModa != nullptr
      ? std::cout << "THE MODA IS " << *getModa.value() << std::endl
      : std::cout << "THE MODA IS THE SAME FOR ALL ELEMENTS" << std::endl;

  return 0;
}
