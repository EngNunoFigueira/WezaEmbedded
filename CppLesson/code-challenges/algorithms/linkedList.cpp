
#include <iostream>
#include <tuple>

using namespace std;

struct Node {
  Node(int _value) : value{_value} {}
  int value{0};
  Node *nextNode{nullptr};
};

int listSize{0};

Node *createLinkedList(int _headerValue) {
  Node *header = new Node((_headerValue));
  return header;
}

tuple<Node *, Node *> insertNewNodeInFront(Node *head, int _value) {
  if (head == nullptr) {
    head = new Node{(_value)};
    ++listSize;
    return {head, nullptr};
  }

  Node *newNode = new Node{(_value)};
  head->nextNode = newNode;
  ++listSize;
  return {newNode, nullptr};
}

tuple<Node *, Node *> insertNewNodeBack(Node *head, int _value) {
  static Node *firstNode{nullptr};
  if (head == nullptr) {
    Node *newNode = new Node((_value));
    head = newNode;
    firstNode = head;
    ++listSize;
    return {head, firstNode};
  }

  Node *newNode = new Node((_value));
  newNode->nextNode = head;
  ++listSize;
  return {newNode, nullptr};
}

void printLinkedList(Node *head) {
  std::cout << "These are the elements stored in the linked list:" << std::endl;
  while (head->nextNode != nullptr) {
    std::cout << head->value << std::endl;
    head = head->nextNode;
  }
  std::cout << head->value << std::endl;
}

bool removeNode(Node *head, const int toBeDelete) {
  Node *previous{nullptr};
  previous = head;
  while (head->nextNode != nullptr) {
    std::cout << "The previous node value is: " << previous->value << std::endl;
    if (head->nextNode->value == toBeDelete) {
      Node *current = head->nextNode;
      std::cout << "Found the node to be deleted" << std::endl;
      std::cout << "The current node value is: " << current->value << std::endl;
      previous->nextNode = current->nextNode;
      delete current;

      return true;
    }
    head = head->nextNode;
    previous = head;
  }
  std::cout << head->value << std::endl;

  return false;
}

tuple<Node *, int> foundElement(Node *head, const int _value) {
  if (head->value == _value) {
    std::cout << "Found : " << head->value << std::endl;
    return {head, head->value};
  }

  while (head->nextNode != nullptr) {
    if (head->nextNode->value == _value) {
      std::cout << "Found : " << head->nextNode->value << std::endl;
      return {head, head->nextNode->value};
    }
    head = head->nextNode;
  }

  return {nullptr, 0};
}

void orderAscLinkedList(Node *head, const int portitionX) {

  int minValue{1000};
  Node *previousPortition{nullptr};
  Node *minValuePosition{nullptr};
  Node *minValuePreviousPosition{nullptr};
  Node *nodePortition = get<0>(foundElement(head, portitionX));

  // Get the previous node of the Portition X to link the minimum values...
  if (nodePortition != nullptr) {
    while (head->nextNode != nullptr) {
      if (head->nextNode == nodePortition) {
        previousPortition = nodePortition->nextNode;
        std::cout << "Congrats we found the previous node of the Portition X"
                  << std::endl;
        std::cout << "previous has the value: "
                  << previousPortition->nextNode->value << std::endl;
      }
      head = head->nextNode;
    }

    // found the actually minimum value after the portitionX
    std::cout << "HERẸ" << std::endl;
    while ((nodePortition->nextNode != nullptr)) {

      nodePortition = nodePortition->nextNode;
      std::cout << "Portition values: " << nodePortition->nextNode->value
                << std::endl;
    }

    // arragement the Linked list after found the min value
    previousPortition->nextNode = minValuePosition;
    minValuePosition->nextNode = nodePortition;
    if (minValuePosition->nextNode == nullptr) {
      // The minimum is the last value of the list...
      minValuePreviousPosition->nextNode = nullptr;
    } else {
      // vamos buscar o indice que está depois do min y vamos ligar ao outro ...
      minValuePreviousPosition->nextNode = minValuePosition->nextNode;
    }
  }
}

void portitionXOrder(Node *head, const int portitionX) {

  bool searchMin{true};
  int minValue{1000};
  Node *auxHead{head};
  Node *previousPortition{nullptr};
  Node *minValuePosition{nullptr};
  Node *minValuePreviousPosition{nullptr};
  Node *nodePortition = get<0>(foundElement(head, portitionX));

  // Get the previous node of the Portition X to link the minimum values...
  if (nodePortition != nullptr) {
    while (head->nextNode != nullptr) {
      if (head->nextNode == nodePortition) {
        previousPortition = nodePortition->nextNode;
        std::cout << "Congrats we found the previous node of the Portition X"
                  << std::endl;
        std::cout << "previous has the value: "
                  << previousPortition->nextNode->value << std::endl;
      }
      head = head->nextNode;
    }
    for (int i{0}; i < listSize; ++i) {
      while (auxHead->nextNode != nullptr) {
        if (searchMin && (minValue > auxHead->nextNode->value)) {
          minValue = auxHead->nextNode->value;
          minValuePreviousPosition = auxHead;
          std::cout << "MINIMUM VALUE : " << minValue << std::endl;
          std::cout << "MINIMUM VALUE PREVIOUS NODE: "
                    << minValuePreviousPosition->value << std::endl;
          minValuePosition = auxHead->nextNode;
        }

        int previousValue{auxHead->nextNode->value};
        if ((previousValue == portitionX) && (searchMin))
          searchMin = false;
        auxHead = auxHead->nextNode;
      }
    }

    std::cout << "The minimum value is: " << minValue << std::endl;
    std::cout << "minValuePosition->value : " << minValuePosition->value
              << std::endl;
    std::cout << "minValuePosition->nextNode->value : "
              << minValuePosition->nextNode->value << std::endl; // refe 2
    std::cout << "The minValue Previous Position value is: "
              << minValuePreviousPosition->value << std::endl;

    minValuePreviousPosition->nextNode = minValuePosition->nextNode;

    // put the minimum in correct place
    std::cout << "HERE" << std::endl;

    std::cout << "REFERENCE OF NODE 4" << std::endl;
    std::cout << "THE PREVIOUS VALUES --> previousPortition->nextNode->value = "
              << previousPortition->nextNode->value << std::endl;

    std::cout << "REFERENCE OF NODE 0 " << std::endl;
    std::cout << "THE PREVIOUS VALUES --> "
                 "previousPortition->nextNode->nextNode->value = "
              << previousPortition->nextNode->nextNode->value << std::endl;

    Node *take{previousPortition->nextNode->nextNode};
    Node *takeAfter{previousPortition->nextNode->nextNode->nextNode->nextNode};

    take = minValuePosition;
    minValuePosition->nextNode = takeAfter;
  }
}

int main(int argc, char **argv) {

  Node *head{nullptr};
  Node *firstNode{nullptr};
  head = get<0>(insertNewNodeBack(head, 100));
  head = get<0>(insertNewNodeBack(head, 200));
  head = get<0>(insertNewNodeBack(head, 0));
  head = get<0>(insertNewNodeBack(head, 4));
  head = get<0>(insertNewNodeBack(head, 14));
  head = get<0>(insertNewNodeBack(head, 2));
  head = get<0>(insertNewNodeBack(head, 1));
  head = get<0>(insertNewNodeBack(head, 3));
  head = get<0>(insertNewNodeBack(head, 9));
  head = get<0>(insertNewNodeBack(head, 11));
  head = get<0>(insertNewNodeBack(head, 8));
  std::cout << "The list size is: " << listSize << std::endl;

  printLinkedList(head);
  // portitionXOrder(head, 14);
  removeNode(head, 3);
  printLinkedList(head);

  return 0;
}
