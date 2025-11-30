#include <iostream>

/*
 * Memory Management in C++
 * stack, data segment, and heap are the three main memory areas
 * stack: stores local variables and function call information
 * data segment: stores global/static variables
 * heap: used for dynamic memory allocation (allocated at runtime)
 * all memory is taken from process address space (typically several GBs
 * allocated during program start)
 * C/C++ provides support for memory allocation at runtime using new/delete
 * or malloc/free (C-style); this is called dynamic memory allocation
 * stack and data segment memory is automatically managed by the compiler at
 * runtime
 * heap memory requires manual management by the programmer using
 * new/delete or smart pointers memory leaks occur when allocated memory is not
 * properly deallocated
 */

// memory allocation example using C-style malloc/free
int main() {
  // allocate memory for an interger on the heap
  size_t intSize = sizeof(int);
  std::cout << "Size of int: " << intSize << " bytes" << std::endl;
  int* intPtr = (int*)std::malloc(intSize);  // malloc returns void* that needs
                                             // to be casted
  if (intPtr == nullptr) {
    std::cerr << "Memory allocation failed!" << std::endl;
    return 1;  // exit with error
  }
  std::cout << "Dynamically allocated integer address: " << intPtr << std::endl;
  *intPtr = 42;  // assign value
  std::cout << "Modified integer value: " << *intPtr << std::endl;
  std::free(intPtr);  // free allocated memory
  // std::free(intPtr);  // double free - undefined behavior (may crash) //
  // SIGABRT
  // that is why it's good practice to set pointer to nullptr after free
  intPtr = nullptr;
  std::free(intPtr);  // safe to free nullptr - no operation performed
  std::cout << std::endl;

  // allocate memory for an integer using calloc
  int* callocPtr = (int*)std::calloc(1, intSize);  // allocates and
                                                   // initializes to zero
  if (callocPtr == nullptr) {
    std::cerr << "Memory allocation failed!" << std::endl;
    return 1;  // exit with error
  }
  std::cout << "Dynamically allocated integer initialized value using calloc: "
            << *callocPtr << std::endl;  // should be 0
  *callocPtr = 84;                       // assign value
  std::cout << "Modified integer value: " << *callocPtr << std::endl;
  std::free(callocPtr);  // free allocated memory
  callocPtr = nullptr;
  std::cout << std::endl;
}
