#include <iostream>

/*
 * Non static vs Static Members in C++
 * Non-static members: Each object of the class has its own copy of non-static
 * members. Changes made to non-static members of one object do not affect other
 * objects.
 * Static members: There is only one copy of static members shared among all
 * objects of the class. Changes made to static members affect all objects.
 * Static members are associated with the class itself rather than any specific
 * object.
 * Syntax:
 * class ClassName {
 * public:
 *   // Non-static member
 *   int nonStaticMember;
 *   // Static member
 *   static int staticMember;
 * };
 */

class Counter {
public:
  // Non-static member
  int nonStaticCount{0};
  // Static member
  static int staticCount;

  // Member function to increment counts
  void increment() {
    nonStaticCount++;
    staticCount++;
  }

  // Member function to display counts
  void displayCounts() {
    std::cout << "Non-static Count: " << nonStaticCount << std::endl;
    std::cout << "Static Count: " << staticCount << std::endl;
  }
};

// Initialize static member
int Counter::staticCount = 0;
int main() {
  Counter obj1;
  Counter obj2;

  obj1.increment();
  obj1.increment();
  obj2.increment();

  std::cout << "Object 1 Counts:" << std::endl;
  obj1.displayCounts();
  std::cout << std::endl;

  std::cout << "Object 2 Counts:" << std::endl;
  obj2.displayCounts();

  return 0;
}
