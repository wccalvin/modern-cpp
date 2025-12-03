#include <iostream>

/*
 * Memory Management in C++ using new/delete for arrays
 * new[]: allocates memory for an array on the heap and returns a pointer to the
 * first element
 * delete[]: deallocates memory previously allocated with new[] to prevent
 * memory leaks
 * syntax: Type* ptr = new Type[size]; // allocation
 *         delete[] ptr; // deallocation
 */

int main() {
  // allocate memory for an array of 5 integers on the heap
  int* intArrayPtr = new int[5];  // allocate memory for array
  std::cout << "Dynamically allocated integer array address: " << intArrayPtr
            << std::endl;

  // assign values to the array elements
  for (int i = 0; i < 5; ++i) {
    intArrayPtr[i] = i * 10;  // assign values
  }

  // print the array elements
  std::cout << "Array elements: ";
  for (size_t i = 0; i < 5; ++i) {
    std::cout << intArrayPtr[i] << " ";
  }
  std::cout << std::endl;

  delete[] intArrayPtr;  // free allocated memory for array
  // delete intArrayPtr; // this might only delete the first element - undefined
  // and it'll compile but is incorrect
  // delete[] intArrayPtr;  // double delete
  // - undefined behavior (may crash) // SIGABRT that is why it's good practice
  // to set pointer to nullptr after delete[]
  intArrayPtr = nullptr;
  delete[] intArrayPtr;  // safe to delete nullptr - no operation performed
  std::cout << std::endl;

  // str_copy example using new[] for character array
  const char* original = "Hello, World!";
  size_t length = std::strlen(original);
  char* copy = new char[length + 1];  // allocate memory for copy (+1 for null
                                      // terminator)
  std::strcpy(copy, original);        // copy the string
  std::cout << "Original string: " << original << std::endl;
  std::cout << "Copied string: " << copy << std::endl;
  delete[] copy;  // free allocated memory for copy
  copy = nullptr;
  std::cout << std::endl;

  // initialize array using new[]
  int* initArray = new int[3]{1, 2, 3};  // allocate and initialize array
  std::cout << "Initialized array elements: ";
  for (size_t i = 0; i < 3; ++i) {
    std::cout << initArray[i] << " ";  // print elements
  }
  std::cout << std::endl;
  delete[] initArray;  // free allocated memory
  initArray = nullptr;
  return 0;
}