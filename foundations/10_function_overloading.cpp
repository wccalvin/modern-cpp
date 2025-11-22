#include <iostream>

/*
 * function overloading allows multiple functions with the same name
 * but different parameter lists (different types or number of parameters)
 * the compiler differentiates them based on the arguments used in the call
 * (static polymorphism)
 * helps provide different implementations for similar operations
 * qualifiers like const, &, and && are considered in overload resolution
 * name mangling is used by the compiler to generate unique names for each
 * overloaded function
 * extern C linkage can be used to prevent name mangling for interoperability
 * with C code
 */

// overloaded function to add two integers
int add(int a, int b) { return a + b; }
// overloaded function to add two doubles
double add(double a, double b) { return a + b; }
// overloaded function to concatenate two strings
std::string add(const std::string& a, const std::string& b) { return a + b; }
// overloaded function to add three integers
int add(int a, int b, int c) { return a + b + c; }
// example of extern "C" to prevent name mangling
extern "C" int c_add(int a, int b) { return a + b; }

int main() {
  // calling overloaded functions
  std::cout << "Add integers: " << add(2, 3)
            << std::endl;  // calls int add(int, int)
  std::cout << "Add doubles: " << add(2.5, 3.5)
            << std::endl;  // calls double add(double, double)
  std::cout << "Add strings: "
            << add(std::string("Hello, "), std::string("World!")) << std::endl;
  std::cout << "Add three integers: " << add(1, 2, 3)
            << std::endl;  // calls int add(int, int, int)

  return 0;
}