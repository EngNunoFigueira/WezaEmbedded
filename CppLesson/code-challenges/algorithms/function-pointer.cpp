#include <exception>
#include <iostream>
#include <optional>

using namespace std;

enum class operation : int { SUM = 1, SUB, MULT, DIV };

/**
 * In order to make the code more readable we define an enum class with names of
 * the basic math operations. And this is function is the helper method that
 * transate the user option, get in the argv[3], in command line, to the exact
 * value of the enum class.
 */
operation userChoose(const char *mathOp) {
  int userSelectMathOp{std::atoi(mathOp)};
  switch (userSelectMathOp) {
  case 1:
    return operation::SUM;
    break;
  case 2:
    return operation::SUB;
    break;
  case 3:
    return operation::MULT;
    break;
  case 4:
    return operation::DIV;
    break;
  default:
    return operation::SUM;
    break;
  }
}

/**
 * Each one of the functions declared below represent the one of the basic
 * operations of the MATH. Now in the main function we declare an array of
 * functions that will using this methods.
 */
int addValues(const char *operandA, const char *operandB) {
  return (std::atoi(operandA) + std::atoi(operandB));
}

int subValues(const char *operandA, const char *operandB) {
  if (std::atoi(operandB) < std::atoi(operandA)) {
    return 0;
  }
  return (std::atoi(operandA) - std::atoi(operandB));
}

int multiValues(const char *operandA, const char *operandB) {
  return (std::atoi(operandA) * std::atoi(operandB));
}

int divValues(const char *operandA, const char *operandB) {
  if (std::atoi(operandB) == 0) {
    return 0;
  }
  return abs(std::atoi(operandA) / std::atoi(operandB));
}

int main(int argc, char **argv) {

  /**
   * This is the definition of the function pointer we pretend to use in order
   * to create an array of functions The purpose of this array of functions is
   * to call different functions using the same array. This is useful to testing
   * embededded firmware used in microcontroller.
   */
  typedef int (*functionArray)(const char *, const char *);
  functionArray mathBasicOp[4] = {addValues, subValues, multiValues, divValues};

  /**
   * This function pointer get the address of the function named addValues.
   * The purpose of this features is passed this pointer function as a parameter
   * of a callback method.
   */
  int (*functionPtr)(const char *, const char *) = addValues;
  // std::cout<<"The sum of "<< std::atoi(argv[1])<< " + "<<
  // std::atoi(argv[2])<< " = "<< functionPtr(argv[1], argv[2])<<std::endl;

  if (argc < 4) {
    std::cout << "Please select one of the following math operations listed "
                 "below\n[ SUM SUB MULT or DIV ]"
              << std::endl;
    return 0;
  }

  operation math{userChoose(argv[3])};
  switch (math) {
  case operation::SUM:
    std::cout << "The sum of " << std::atoi(argv[1]) << " + "
              << std::atoi(argv[2]) << " = " << mathBasicOp[0](argv[1], argv[2])
              << std::endl;
    break;
  case operation::SUB:
    std::cout << "The sub of " << std::atoi(argv[1]) << " - "
              << std::atoi(argv[2]) << " = " << mathBasicOp[1](argv[1], argv[2])
              << std::endl;
    break;
  case operation::MULT:
    std::cout << "The mult of " << std::atoi(argv[1]) << " * "
              << std::atoi(argv[2]) << " = " << mathBasicOp[2](argv[1], argv[2])
              << std::endl;
    break;
  case operation::DIV:
    std::cout << "The div of " << std::atoi(argv[1]) << " / "
              << std::atoi(argv[2]) << " = " << mathBasicOp[3](argv[1], argv[2])
              << std::endl;
    break;
  default:
    std::cout << "Any valid option was" << std::endl;
    break;
  }

  return 0;
}
