#include <iostream>

int main() {
  int i; // contains junk value without initializing
  std::cout << i << std::endl;

  int j = 0;
  std::cout << j << std::endl;

  char a = 'c';
  std::cout << a << std::endl;

  bool b = true;
  std::cout << b << std::endl;

  float f = 1.345f;
  std::cout << f << std::endl;

  double d = 1.345;
  std::cout << d << std::endl;

  return 0;
}