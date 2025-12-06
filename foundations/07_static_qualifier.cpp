#include <iostream>

/*
 * static Qualifier:
 * static local variables retain their value between function calls
 * static global variables and functions have internal linkage (limited to the
 * translation unit)
 * commonly used in classes to define class-level variables and methods
 * that are shared among all instances of the class
 */

// static local variable example
void counterFunction() {
  static int count = 0; // retains its value between calls
  count++;
  std::cout << "Counter: " << count << std::endl;
}
// static global variable example
static int globalStaticVar = 0; // limited to this translation unit
void incrementGlobalStaticVar() { globalStaticVar++; }
void decrementGlobalStaticVar() { globalStaticVar--; }
void printGlobalStaticVar() {
  std::cout << "Global Static Variable: " << globalStaticVar << std::endl;
}
// static member variable and function example
class MyClass {
public:
  static int staticMemberVar; // shared among all instances
  static void staticMemberFunction() {
    std::cout << "Static Member Variable: " << staticMemberVar << std::endl;
  }
};

int MyClass::staticMemberVar = 42; // definition of static member variable

int main() {
  // Demonstrate static local variable
  counterFunction(); // Counter: 1
  counterFunction(); // Counter: 2
  counterFunction(); // Counter: 3
  std::cout << std::endl;

  // Demonstrate static global variable
  printGlobalStaticVar(); // Global Static Variable: 0
  incrementGlobalStaticVar();
  incrementGlobalStaticVar();
  printGlobalStaticVar(); // Global Static Variable: 2
  decrementGlobalStaticVar();
  printGlobalStaticVar(); // Global Static Variable: 1
  std::cout << "globalStaticVar directly: " << globalStaticVar << std::endl;
  std::cout << std::endl;

  // Demonstrate static member variable and function
  MyClass::staticMemberFunction(); // Static Member Variable: 42
  MyClass::staticMemberVar = 100;
  MyClass::staticMemberFunction(); // Static Member Variable: 100

  return 0;
}
