#include <iostream>

/*
 * namespace: a declarative region that provides a scope to the identifiers
 * (names of types, functions, variables, etc.) inside it
 * helps avoid name collisions especially in large projects or when using
 * multiple libraries
 * syntax: namespace name { declarations }
 * can be nested and can be accessed using the scope resolution operator (::)
 * the 'using' directive can bring all names from a namespace into the current
 * scope, while the 'using' declaration can bring in specific names
 */

// example of defining and using a namespace
namespace MathUtils {
// function to add two integers
int add(int a, int b) { return a + b; }
// function to multiply two integers
int multiply(int a, int b) { return a * b; }
} // namespace MathUtils

// why using keyword is not recommended in header files
// it can lead to name collisions when the header is included in multiple files
// here's an example of using the namespace in main
// namespace avg {
double compute(double a, double b) { return (a + b) / 2; }
// }  // namespace avg
// global compute function that causes a name conflict
// double compute(double a, double b) { return a + b; }

// this can be solved using namespaces
namespace avgOps {
double compute(double a, double b) { return (a + b) / 2; }
} // namespace avgOps
namespace addOps {
double compute(double a, double b) { return a + b; }
} // namespace addOps

// example of using namespace without name
namespace {
void helperFunction() {
  std::cout << "This is a helper function in an unnamed namespace."
            << std::endl;
}
} // namespace
int main() {
  // namespace conflict example
  double avgValue = avgOps::compute(4.0, 6.0); // calls
  double sumValue = addOps::compute(4.0, 6.0); // calls
  std::cout << "Average: " << avgValue << std::endl;
  std::cout << "Sum: " << sumValue << std::endl;
  std::cout << std::endl;

  // using the MathUtils namespace functions with scope resolution operator
  int sum = MathUtils::add(5, 10);
  int product = MathUtils::multiply(5, 10);
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Product: " << product << std::endl;
  std::cout << std::endl;

  // bringing all names from MathUtils into current scope
  using namespace MathUtils;
  int newSum = add(20, 30); // no need for MathUtils:: prefix
  std::cout << "New Sum: " << newSum << std::endl;
  std::cout << std::endl;
  // calling helper function from unnamed namespace
  helperFunction(); // this cannot be accessed outside this file

  return 0;
}