#include <iostream>

/*
 * inline functions are defined with the 'inline' keyword
 * suggests to the compiler to insert the function's code
 * directly at each call site instead of performing a regular call
 * helps reduce function call overhead for small, frequently called functions
 * can lead to faster execution but may increase static binary size (code bloat)
 * suitable for small functions, such as getters/setters or simple calculations
 * the compiler may ignore the inline suggestion for complex functions
 * inline functions must be defined in header files to be accessible across
 * multiple files
 */

inline int square(int x) { return x * x; }

int main() {
  int num = 5;
  std::cout << "Square of " << num + 1 << " is " << square(num + 1)
            << std::endl;
  return 0;
}