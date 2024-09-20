#include <exception>
#include <iostream>
#include <optional>

using namespace std;

class Exprienced {
public:
  Exprienced(){};
  ~Exprienced(){};

  std::optional<Exprienced> defineMatrixSize(int numbers[], float basic) {
    int arraLen{sizeof(numbers) / sizeof(int)};
    int middle{arraLen / 2};

    if (arraLen > 1) {
      return *this;
    } else {
      return std::nullopt;
    }
  }

  void printMessage(const std::optional<std::string> &message = std::nullopt) {
    if (message == nullopt) {
      std::cout << "This is a function chaining testing concept " << std::endl;
    } else {
      std::cout << " This is the user message : " << message.value()
                << std::endl;
    }
  }
};

int addValues(int operatorA, int operatorB) { return operatorA * operatorB; }

int main(int argc, char **agrv) {

  Exprienced game;
  int values[4] = {9, 3, 6, 12};

  try {
    game.defineMatrixSize(values, 8.1).value().printMessage();
  } catch (std::string error) {
    std::cout << "This is the error " << error << std::endl;
  }

  int (*functionPtr)(int, int) = addValues;

  std::cout << "This is the sum result: " << functionPtr(4, 4) << std::endl;

  return 0;
}