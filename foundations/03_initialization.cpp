#include <iostream>

int main() {
  // value initialization
  int a{};          // a is initialized to 0
  double b{};       // b is initialized to 0.0
  char c{};         // c is initialized to '\0'
  bool d{};         // d is initialized to false
  std::string e{};  // e is initialized to an empty string
  int array[5]{};   // all elements initialized to 0

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << static_cast<int>(c) << std::endl;  // print ASCII value of char
  std::cout << d << std::endl;
  std::cout << e << std::endl;
  std::cout << "Array elements: ";
  for (int i = 0; i < 5; ++i) {
    std::cout << array[i] << " ";  // print each element of the array
  }
  std::cout << std::endl;

  // direct initialization
  int x{42};  // x is initialized to 42
  std::cout << x << std::endl;

  // copy initialization
  double y = 3.14;  // y is initialized to 3.14
  std::cout << y << std::endl;

  /*
   * it forces initialization
   * prevents narrowing conversions
   * uniform syntax for all types
   */

  // narrowing conversions example
  double z{};
  std::cout << z << std::endl;
  z = 7;  // data integrity lost
  std::cout << z << std::endl;

  return 0;
}
