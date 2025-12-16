#include <iostream>

/*
 * type inference with auto:
 * automatically deduces the type of a variable from its initializer
 * const is preserved when using auto but not propagated
 * useful for complex types like iterators, lambdas, templates, etc.
 */

int main() {
  // example of auto type inference
  auto intVar{42};      // int
  auto doubleVar{3.14}; // double
  auto sum =
      intVar + doubleVar; // double (result of int + double) - largest type wins
  std::cout << "intVar: " << intVar << ", type: " << typeid(intVar).name()
            << std::endl;
  std::cout << "doubleVar: " << doubleVar
            << ", type: " << typeid(doubleVar).name() << std::endl;
  std::cout << "sum: " << sum << ", type: " << typeid(sum).name() << std::endl;
  std::cout << std::endl;

  // example of const with auto and caveat of const propagation
  const auto constVar = 100; // const int
  auto newVar = constVar;    // int (const is not propagated)
  std::cout << "constVar: " << constVar << ", type: " << typeid(constVar).name()
            << std::endl;
  std::cout << "newVar: " << newVar << ", type: " << typeid(newVar).name()
            << std::endl;
  newVar = 200; // valid, newVar is not const
  std::cout << "Modified newVar: " << newVar << std::endl;
  std::cout << "newVar: " << newVar << ", type: " << typeid(newVar).name()
            << std::endl;
  std::cout << std::endl;

  // example of const with auto and proper const propagation
  const auto anotherConstVar = 300;           // const int
  const auto anotherNewVar = anotherConstVar; // const int (const is preserved)
  std::cout << "anotherConstVar: " << anotherConstVar
            << ", type: " << typeid(anotherConstVar).name() << std::endl;
  std::cout << "anotherNewVar: " << anotherNewVar
            << ", type: " << typeid(anotherNewVar).name() << std::endl;
  // anotherNewVar = 400;  // Compilation error: cannot modify a const variable
  std::cout << std::endl;

  // example of auto with pointers
  int value = 50;
  int *ptr = &value;      // pointer to int
  auto inferredPtr = ptr; // int* (type of ptr) - note * is not specified
  std::cout << "value: " << value << ", type: " << typeid(value).name()
            << std::endl;
  std::cout << "ptr: " << ptr << ", type: " << typeid(ptr).name() << std::endl;
  std::cout << "inferredPtr: " << inferredPtr
            << ", type: " << typeid(inferredPtr).name() << std::endl;
  *inferredPtr = 60; // modifying value through inferredPtr
  std::cout << "Modified value through inferredPtr: " << value << std::endl;
  std::cout << std::endl;

  // experiment to modify const pointer with auto
  const int num = 5;
  auto ptrNum = &num; // pointer to int
  std::cout << "num: " << num << ", type: " << typeid(num).name() << std::endl;
  std::cout << "ptrNum: " << ptrNum << ", type: " << typeid(ptrNum).name()
            << std::endl;
  // *ptrNum = 10; // Compilation error: cannot modify a const value
  std::cout << std::endl;

  // example of const pointer with auto - proper const propagation happens here
  const auto constPtr = ptr; // int* const (const pointer to int)
  std::cout << "constPtr: " << constPtr << ", type: " << typeid(constPtr).name()
            << std::endl;
  const auto anotherConstPtr = constPtr; // int* const (const pointer to int)
  std::cout << "anotherConstPtr: " << anotherConstPtr
            << ", type: " << typeid(anotherConstPtr).name() << std::endl;
  // anotherConstPtr = 2; // Compilation error: cannot modify a const pointer
  std::cout << "Value through anotherConstPtr: " << *anotherConstPtr
            << std::endl;

  return 0;
}