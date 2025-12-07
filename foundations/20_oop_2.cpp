#include <iostream>

/*
 * Example of constructors and destructors in C++
 * Constructor: A special member function that is called when an object of the
 * class is created. It initializes the object's data members.
 * Destructor: A special member function that is called when an object of the
 * class is destroyed. It is used to release resources that the object may have
 * acquired during its lifetime. The lifetime of an object is typically tied to
 * its scope; when the object goes out of scope, its destructor is called.
 * syntax:
 * class ClassName {
 * public:
 *   // Constructor
 *   ClassName() {
 *     // initialization code
 *   }
 *   // Destructor
 *   ~ClassName() {
 *     // cleanup code
 *   }
 * };
 */

class Car {
public:
  // data members (attributes/properties)
  std::string make;
  std::string model;
  int year;
  std::string color;
  // Constructor
  Car(std::string m, std::string l, int y, std::string r)
      : make(m), model(l), year(y), color(r) {
    std::cout << "Car object created: " << year << " " << color << " " << make
              << " " << model << std::endl;
  }
  // Destructor
  ~Car() {
    std::cout << "Car object destroyed: " << year << " " << color << " " << make
              << " " << model << std::endl;
  }

  // member functions (methods/behaviors)
  void start() { std::cout << "Car started." << std::endl; }
  void stop() { std::cout << "Car stopped." << std::endl; }
  void displayInfo() {
    std::cout << "Car Info: " << year << " " << color << " " << make << " "
              << model << std::endl;
  }
};
int main() {
  {
    // create objects (instances) of the Car class
    std::string make = "Subaru";
    Car car1(make, "WRX", 2021, "Red");
    car1.start();
    car1.displayInfo();
    car1.stop();

    std::cout << std::endl;

    Car car2(make, "Outback", 2018, "White");
    car2.start();
    car2.displayInfo();
    car2.stop();
    std::cout << std::endl;
  } // car1 and car2 go out of scope here, and their destructors are called

  return 0;
}