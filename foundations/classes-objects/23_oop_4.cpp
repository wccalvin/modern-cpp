#include <iostream>

/*
 * this pointer:
 * a special pointer available within non-static member functions
 * points to the object for which the member function is called
 * allows access to the calling object's members and methods
 * useful for distinguishing between member variables and parameters with the
 * same name
 */
class Rectangle {
private:
  double width;
  double height;

public:
  // constructor
  Rectangle(double width, double height) {
    // using this pointer to distinguish member variables from parameters
    this->width = width;
    this->height = height;
  }
  double area() {
    // using this pointer to access member variables
    return this->width * this->height;
  }
  void printDimensions() {
    // using this pointer to call another member function
    std::cout << "Width: " << this->width << ", Height: " << this->height
              << std::endl;
  }

  double getArea() {
    // using this pointer to call another member function
    return this->area();
  }
};

int main() {
  Rectangle rect1(5.0, 3.0);
  Rectangle rect2(8.0, 3.5);
  rect1.printDimensions();
  rect2.printDimensions();
  std::cout << "Area: " << rect1.area() << std::endl;
  std::cout << "Area: " << rect2.area() << std::endl;
  std::cout << "Area via getArea: " << rect1.getArea() << std::endl;
  std::cout << "Area via getArea: " << rect2.getArea() << std::endl;
  return 0;
}