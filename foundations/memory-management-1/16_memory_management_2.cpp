#include <iostream>

/*
 * Memory Management in C++ using new/delete
 * new: allocates memory on the heap and returns a pointer to the allocated
 * memory delete: deallocates memory previously allocated with new to prevent
 * syntax: Type* ptr = new Type; // allocation delete ptr; // deallocation
 */

// memory allocation example using new/delete for an integer
int main() {
  // allocate memory for an integer on the heap
  int *intPtr = new int; // allocate memory - this is uninitialized
  std::cout << "Dynamically allocated integer address: " << intPtr << std::endl;
  // we can also initialize during allocation
  // int* intPtr = new int(42); // allocate and initialize to 42
  *intPtr = 42; // assign value
  std::cout << "Modified integer value: " << *intPtr << std::endl;
  delete intPtr; // free allocated memory
  // delete intPtr;  // double delete - undefined behavior (may crash) //
  // SIGABRT that is why it's good practice to set pointer to nullptr after
  // delete
  intPtr = nullptr;
  delete intPtr; // safe to delete nullptr - no operation performed
  std::cout << std::endl;
  // in c++, it is recommended to use new/delete over malloc/free for better
  // type safety and constructors/destructors support
}