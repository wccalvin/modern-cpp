#include <iostream>

/*
 * struct in C++
 * similar to class, but default access specifier is public
 * typically used for simple data structures that group related variables
 * can have member functions, constructors, destructors, and access specifiers
 * syntax:
 * struct StructName {
 *   data_members;   // attributes/properties
 *   member_functions; // methods/behaviors
 * };
 */

struct Point {
  // data members (attributes/properties)
  int x;
  int y;
  // Constructor
  Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
  // member function (method/behavior)
  void display() { std::cout << "Point(" << x << ", " << y << ")"; }
  ~Point() {
    std::cout << "Point object destroyed: (" << x << ", " << y << ")"
              << std::endl;
  }
};

void drawLine(Point &p1, Point &p2) {
  std::cout << "Drawing line from ";
  p1.display();
  std::cout << " to ";
  p2.display();
  std::cout << std::endl;
}

int main() {
  // create instances of the Point struct
  Point pointA(2, 3);
  Point pointB(5, 7);

  // use member function
  pointA.display();
  std::cout << " ";
  pointB.display();
  std::cout << std::endl;

  std::cout << std::endl;

  // use function that takes struct as parameters
  drawLine(pointA, pointB);

  return 0;
}