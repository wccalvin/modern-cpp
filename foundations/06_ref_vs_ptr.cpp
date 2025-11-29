#include <iostream>

// swap two integers using value parameters
void swapByValue(int a, int b) {
  // this swap will not affect the original arguments as we are working with
  // copies
  int temp = a;
  a = b;
  b = temp;
}

// swap by address (using pointers) - for reference
void swapByAddress(int* a, int* b) {
  // when using pointers, we have to check for null pointers in real code
  int temp = *a;
  *a = *b;  // dereferencing pointer b to get value and assign it to another
            // pointer a
  *b = temp;
}

// swap by reference using C++ references - for reference
void swapByReference(int& a, int& b) {
  // this syntax is cleaner; no null pointer checks needed
  int temp = a;
  a = b;  // no dereferencing needed
  b = temp;
}

int main() {
  int a = 5;
  int b = 10;

  std::cout << "Before swapByValue: a = " << a << ", b = " << b << std::endl;
  swapByValue(a, b);
  std::cout << "After swapByValue: a = " << a << ", b = " << b << " (no change)"
            << std::endl;

  std::cout << "Before swapByAddress: a = " << a << ", b = " << b << std::endl;
  swapByAddress(&a, &b);
  std::cout << "After swapByAddress: a = " << a << ", b = " << b << " (swapped)"
            << std::endl;

  std::cout << "Before swapByReference: a = " << a << ", b = " << b
            << std::endl;
  swapByReference(a, b);
  std::cout << "After swapByReference: a = " << a << ", b = " << b
            << " (swapped)" << std::endl;

  return 0;
}