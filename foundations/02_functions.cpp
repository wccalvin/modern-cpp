#include <iostream>

int add(int, int);

int main() {
  int x, y;

  std::cout << "Provide two values seperated by spaces: ";
  std::cin >> x >> y;
  int sum = add(x, y);
  std::cout << "Sum (" << x << " + " << y << ") is " << sum << std::endl;
  return 0;
}

int add(int x, int y) {
  int sum = x + y;
  return sum;
}