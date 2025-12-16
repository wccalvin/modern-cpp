#include <iostream>

/*
 * Object-Oriented Programming (OOP) Concepts in C++
 * Classes and Objects
 * - Class: A blueprint for creating objects, encapsulating data for the object
 *   and methods to manipulate that data.
 * - Object: An instance of a class.
 * Abstraction
 * - Hiding complex implementation details and showing only the essential
 *   features of the object.
 * Encapsulation
 * - Bundling data and methods that operate on that data within a single unit
 *   (class), restricting direct access to some of the object's components.
 * Inheritance
 * - Mechanism by which one class (derived class) can inherit properties and
 *   behaviors (methods) from another class (base class).
 * Composition
 * - Building complex types by combining objects of other types, promoting code
 *   reuse and flexibility.
 * Polymorphism
 * - Ability of different classes to be treated as instances of the same class
 *   through a common interface, typically via base class pointers or
 *   references.
 */

/*
 * class
 * blueprint/template or recipe for creating objects
 * represents an abstraction
 * every objection is an instance of a class
 * can have multiple instances (objects) of the same class and they are
 * independent
 * syntax:
 * class ClassName {
 *   access_specifier:  // public, private, protected
 *     data_members;   // attributes/properties
 *     member_functions; // methods/behaviors
 * };
 */
class Car {
  // by default, members are private
public:
  // data members (attributes/properties)
  std::string make;
  std::string model;
  int year;
  std::string color;
  // member functions (methods/behaviors)
  void start() { std::cout << "Car started." << std::endl; }
  void stop() { std::cout << "Car stopped." << std::endl; }
  void displayInfo() {
    std::cout << "Car Info: " << year << " " << color << " " << make << " "
              << model << std::endl;
  }
};

int main() {
  // create objects (instances) of the Car class
  Car car1;
  car1.make = "Subaru";
  car1.model = "WRX";
  car1.year = 2021;
  car1.color = "Red";

  Car car2;
  car2.make = "Subaru";
  car2.model = "Outback";
  car2.year = 2018;
  car2.color = "White";

  // use member functions
  car1.start();
  car1.displayInfo();
  car1.stop();

  std::cout << std::endl;

  car2.start();
  car2.displayInfo();
  car2.stop();

  return 0;
}
