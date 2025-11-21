#include <iostream>

/*
 * Const Qualifier:
 * Used to define variables whose value cannot be changed after initialization
 * always needs to be initialized during declaration
 * replaces the need for #define macros for constants
 * commonly used with pointers and references to prevent modification of the
 * referent
 * it has scope and type like regular variables unlike macros
 * pointer to a const variable should also be declared as const (it will give a
 * compilation error otherwise)
 */

const float PI = 3.14159f;  // constant variable for pi
float areaOfCircle(const float radius) { return PI * radius * radius; }
float circumferenceOfCircle(const float radius) { return 2 * PI * radius; }

int main() {
  float r = 5.0f;
  std::cout << "Area of circle with radius " << r << " is " << areaOfCircle(r)
            << std::endl;
  std::cout << "Circumference of circle with radius " << r << " is "
            << circumferenceOfCircle(r) << std::endl;

  const int a = 3;
  // a = 4; // Compilation error: cannot modify a const variable
  std::cout << "Value of const variable a: " << a << std::endl;
  // int* aPtr = a; // Compilation error: cannot convert from 'const int*' to
  // 'int*'
  const int* constAPtr = &a;  // pointer to a const int
  std::cout << "Value pointed to by constAPtr: " << *constAPtr << std::endl;
  // try another way using reference
  // int aRef = &a;  // Compilation error: cannot bind non-const lvalue
  // reference to a const int
  const int& constARef = a;  // reference to a const int
  std::cout << "Value referred to by constARef: " << constARef << std::endl;

  return 0;
}