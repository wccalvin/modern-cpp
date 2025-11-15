#include <iostream>

/*
 * Reference Type:
 * Defines an alternative name for a variable (an alias)
 * Created using the & operator during declaration
 * Always needs an initializer (referent)
 * referent should be variable
 * it can be used to modify a variable indirectly (like a pointer)
 * reference is NOT a new variable; its just another name (no memory is
 * allocated for a reference)
 */

int main() {
  int x = 7;
  int& ref = x;  // x is referent and ref is reference to x
  std::cout << "Value of x: " << x << std::endl;
  std::cout << "Value of ref: " << ref
            << std::endl;  // dereferencing not needed
  std::cout << "Address of x: " << &x << std::endl;
  std::cout << "Address of ref: " << &ref << std::endl;
  // modifying value through reference
  ref = 20;
  std::cout << "Modified Value of x by modifying ref: " << x << std::endl;
  std::cout << "Value of ref after modifying x: " << ref << std::endl;

  return 0;
}