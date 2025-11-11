#include <iostream>

/*
 * Pointers in C++
 * pointer points to the memory address of the same type variable
 * declared using the asterisk (*) symbol & operator is
 * used to get the address of a variable nullptr is used to represent a null
 * pointer pointers can be dereferenced using the asterisk (*) to access or
 * modify the value
 */
int main() {
  // declaring a pointer
  int* ptr{nullptr};  // pointer to an integer

  // declaring and initializing a pointer to the address of a variable
  int value = 42;
  int* valuePtr = &value;  // valuePtr holds the address of value

  std::cout << "Value: " << value << std::endl;
  std::cout << "Address of value: " << &value << std::endl;
  std::cout << "Pointer valuePtr: " << valuePtr << std::endl;
  std::cout << "Value through pointer dereferencing: " << *valuePtr
            << std::endl;

  // try assingning differnt type address to pointer
  double dvalue = 3.14;
  // ptr = &dvalue;  // compilation error: cannot convert from 'double*' -
  // use void* to solve this issue
  void* voidPtr = &dvalue;  // void pointer can hold any type address

  // modifying value through pointer dereferencing
  *valuePtr = 100;
  std::cout << "Modified Value: " << value
            << std::endl;  // note the value of value has changed as well

  // can't read or write through null pointer
  // std::cout << *ptr << std::endl; // runtime error: dereferencing null
  // pointer
  // *ptr = 10;  // runtime error: dereferencing null pointer

  return 0;
}