#include <iostream>

/*
 * const member functions:
 * member functions that do not modify the state of the object
 * indicated by the const keyword after the function signature
 * can be called on const instances of the class
 * helps enforce immutability and improves code safety
 */

class Circle {
private:
  double radius;

public:
  // constructor
  Circle(double r) : radius(r) {}
  // const member function to calculate area
  double area() const { return 3.14159 * radius * radius; }
  // const member function to get radius
  double getRadius() const { return radius; }
  // non-const member function to set radius
  void setRadius(double r) { radius = r; }
};

int main() {
  Circle circle1(5.0);
  std::cout << "Circle 1 Radius: " << circle1.getRadius() << std::endl;
  std::cout << "Circle 1 Area: " << circle1.area() << std::endl;

  // Modifying radius using non-const member function
  circle1.setRadius(10.0);
  std::cout << "Circle 1 New Radius: " << circle1.getRadius() << std::endl;
  std::cout << "Circle 1 New Area: " << circle1.area() << std::endl;
  std::cout << std::endl;

  // Creating a const instance of Circle
  const Circle circle2(7.0);
  std::cout << "Circle 2 Radius: " << circle2.getRadius() << std::endl;
  std::cout << "Circle 2 Area: " << circle2.area() << std::endl;

  // The following line would cause a compilation error
  // circle2.setRadius(14.0); // Error: cannot call non-const function on const
  // object

  return 0;
}