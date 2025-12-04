#include <iostream>

/*
 * 2D Array Memory Management in C++ using new/delete for arrays
 * new[]: allocates memory for an array on the heap and returns a pointer to the
 * first element
 * delete[]: deallocates memory previously allocated with new[] to prevent
 * memory leaks
 * syntax: Type** ptr = new Type*[rows]; // allocate array of pointers for rows
 *         for (size_t i = 0; i < rows; ++i) {
 *           ptr[i] = new Type[cols]; // allocate each row
 *         }
 *         // deallocation
 *         for (size_t i = 0; i < rows; ++i) {
 *           delete[] ptr[i]; // free each row
 *         }
 *         delete[] ptr; // free array of pointers for rows
 */

int main() {
  const size_t rows = 3;
  const size_t cols = 4;
  // regular 2D array on stack
  int stackArray[rows][cols] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::cout << "Stack 2D Array:" << std::endl;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << stackArray[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // representation of the same 2D array using dynamic memory allocation
  int** heapArray = new int*[rows];  // allocate array of pointers for rows
  for (size_t i = 0; i < rows; ++i) {
    heapArray[i] = new int[cols];  // allocate each row
  }
  // assign values to the dynamically allocated 2D array
  int value = 1;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      heapArray[i][j] = value++;
    }
  }
  // print the dynamically allocated 2D array
  std::cout << "Heap 2D Array:" << std::endl;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << heapArray[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // deallocate memory for the dynamically allocated 2D array
  for (size_t i = 0; i < rows; ++i) {
    delete[] heapArray[i];  // free each row
  }
  delete[] heapArray;   // free array of pointers for rows
  heapArray = nullptr;  // set pointer to nullptr after deletion

  // initialize 2D array using new on the heap
  int** initArray = new int*[2];  // allocate array of pointers for rows
  for (size_t i = 0; i < 2; ++i) {
    initArray[i] = new int[3];  // allocate each row
  }
  // initialize values
  initArray[0][0] = 10;
  initArray[0][1] = 20;
  initArray[0][2] = 30;
  initArray[1][0] = 40;
  initArray[1][1] = 50;
  initArray[1][2] = 60;
  // print initialized array
  std::cout << "Initialized Heap 2D Array:" << std::endl;
  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      std::cout << initArray[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // deallocate memory
  for (size_t i = 0; i < 2; ++i) {
    delete[] initArray[i];  // free each row
  }
  delete[] initArray;   // free array of pointers for rows
  initArray = nullptr;  // set pointer to nullptr after deletion

  // simple representation of 2D array using single allocation
  int* p1 = new int[3];
  int* p2 = new int[3];
  int** twoDArray = new int*[2];
  twoDArray[0] = p1;
  twoDArray[1] = p2;
  // assign values
  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      twoDArray[i][j] = (i + 1) * (j + 1) * 5;
    }
  }
  // print values
  std::cout << "Simple Representation of 2D Array:" << std::endl;
  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      std::cout << twoDArray[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // deallocate memory
  delete[] p1;
  delete[] p2;
  delete[] twoDArray;
  twoDArray = nullptr;  // set pointer to nullptr after deletion
  return 0;
}