#include <iostream>

int main() {
  // for loop to print numbers from 1 to 5
  /*
   * syntax: for (initialization; condition; increment) { // loop body }
   * initialization: executed once at the beginning
   * condition: checked before each iteration; if true, loop body executes
   * increment: executed after each iteration
   * provides more control over the loop
   */
  for (int i = 1; i <= 5; ++i) {
    std::cout << "Number: " << i << std::endl;
  }

  // range-based for loop to iterate over an array
  /*
   * allows iteration over elements in a collection (like arrays, vectors, etc.)
   * syntax: for (declaration : collection) { // use declaration }
   * automatically handles begin and end of the collection
   * does not require explicit indexing
   */
  int arr[] = {10, 20, 30, 40, 50};
  for (const auto& num : arr) {
    std::cout << "Array element: " << num << std::endl;
  }

  // to change the value in range-based for loop, use non-const reference
  for (auto& num : arr) {
    num *= 10;  // modify each element by multiplying by 10
  }
  std::cout << "Modified array elements:" << std::endl;
  for (const auto& num : arr) {
    std::cout << "Array element: " << num << std::endl;
  }

  // range-based for loop explanation with begin() and end()
  /*
   * range-based for loop internally uses begin() and end() functions
   * begin() returns an iterator to the first element
   * end() returns an iterator to one past the last element
   * loop iterates from begin() to end()
   */
  std::cout << "Using begin() and end() explicitly:" << std::endl;
  for (auto it = std::begin(arr); it != std::end(arr); ++it) {
    std::cout << "Array element pointer: " << it << std::endl;
    *it /= 10;  // revert each element back by dividing by 10 and assigning it
                // to pointer
    std::cout << "Array element: " << *it
              << std::endl;  // dereference pointer to get value
  }

  return 0;
}