#include <iostream>

/*
 * Const Qualifier:
 * Used to define variables whose value cannot be changed after initialization
 * always needs to be initialized during declaration
 * replaces the need for #define macros for constants
 * commonly used with pointers and references to prevent modification of the
 * referent
 * it has scope and type like regular variables unlike macros
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

  return 0;
}