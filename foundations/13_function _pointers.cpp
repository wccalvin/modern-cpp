#include <iostream>

/*
 * function pointers allow you to store the address of a function
 * and call the function through that pointer
 * useful for callbacks, event handling, and implementing function tables
 * syntax: return_type (*pointer_name)(parameter_types)
 * can point to functions with matching signatures
 * can be reassigned to point to different functions
 * can be passed as arguments to other functions
 * can be returned from functions
 */

// example using callback with function pointer
void greetMorning() { std::cout << "Good morning!" << std::endl; }

void greetEvening() { std::cout << "Good evening!" << std::endl; }
void sayBye() { std::cout << "Goodbye!" << std::endl; }
void executeGreeting(void (*greetFunc)()) {
  greetFunc();  // call the function through the pointer
}

int main() {
  // declare a function pointer and assign it to greetMorning
  void (*greetPtr)() = greetMorning;
  greetPtr();  // calls greetMorning

  // reassign the function pointer to greetEvening
  greetPtr = greetEvening;
  greetPtr();  // calls greetEvening

  // using function pointer as a callback
  executeGreeting(greetMorning);  // calls greetMorning
  executeGreeting(greetEvening);  // calls greetEvening

  // atexit example
  void (*byePtr)() = sayBye;
  std::atexit(byePtr);  // register greetMorning to be called at exit
  std::cout << "Program is running..." << std::endl;
  std::cout << "Program is ending..." << std::endl;

  return 0;
}