#include <iostream>

/*
 * static class members:
 * static member variables are shared among all instances of the class
 * static member functions can be called without an instance of the class
 * useful for class-level data and behavior
 * some important points:
 * - static member variables must be defined outside the class
 * - static member variables are initialized only once before any object is
 * created
 * - definition of static member variable is not allowed inside another function
 * - static member functions do not have access to the this pointer
 * - static member functions can only access static member variables and other
 *   static member functions
 * - static member functions cannot access non-static members directly
 * - static members are accessed using the class name
 * syntax:
 * class ClassName {
 *   static DataType staticMemberVariable;
 *   static ReturnType staticMemberFunction();
 * };
 */

class Counter {
private:
  static int count; // static member variable to keep track of count
public:
  // static member function to increment count
  static void increment() { count++; }
  // static member function to get current count
  static int getCount() { return count; }
};

class AnotherCounter {
private:
  static int another_count; // static member variable to keep track of count
public:
  // non static member function to increment count
  void increment() { another_count++; }
  // static member function to get current count
  static int getCount() { return another_count; }
};

// Definition of static member variable
int Counter::count = 0;
int AnotherCounter::another_count = 0;

int main() {
  std::cout << "Initial Count: " << Counter::getCount() << std::endl;

  // Incrementing count using static member function
  Counter::increment();
  Counter::increment();
  std::cout << "Count after 2 increments: " << Counter::getCount() << std::endl;
  std::cout << std::endl;

  // Creating instances of Counter class
  Counter c1;
  Counter c2;

  // Incrementing count using static member function via instances
  c1.increment();
  c2.increment();
  std::cout << "Count after 2 more increments: " << Counter::getCount()
            << std::endl;
  std::cout << std::endl;

  // Using AnotherCounter class
  AnotherCounter ac1;
  AnotherCounter ac2;
  ac1.increment();
  ac2.increment();
  std::cout << "AnotherCounter Count after 2 increments: "
            << AnotherCounter::getCount() << std::endl;

  return 0;
}