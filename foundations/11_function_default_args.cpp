#include <iostream>

/*
 * arguments can have default values specified in the function declaration
 * if an argument is not provided in the function call, the default value is
 * used default arguments must be the trailing arguments in the parameter list
 * helps simplify function calls by reducing the number of required arguments
 */

// cannot have non-default argument after a default argument
// void exampleFunc(int a = 10, int b); // invalid
void displayInfo(const std::string& name, int age = 18,
                 const std::string& city = "Unknown") {
  std::cout << "Name: " << name << ", Age: " << age << ", City: " << city
            << std::endl;
}

int main() {
  // calling function with all arguments
  displayInfo("Alice", 25, "New York");
  // calling function with one default argument (city)
  displayInfo("Bob", 30);
  // calling function with two default arguments (age and city)
  displayInfo("Charlie");
  // cannot skip middle arguments, must provide preceding ones
  // displayInfo("David", , "Los Angeles"); // invalid

  return 0;
}