#include <iostream>

class AddNumbers {
public:
  int a;
  int b;
  AddNumbers(int x, int y) : a(x), b(y) {
    std::cout << "Constructor is called" << std::endl;
  }
  ~AddNumbers() { std::cout << "Destructor is called" << std::endl; }
  int add() { return a + b; }
};

int main() {
  AddNumbers plusAB(7, 14);
  int result = plusAB.add();
  std::cout << result << std::endl;
  return 0;
}
