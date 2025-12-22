#include <iostream>

/*
Copy constructor:
- Creates a copy of the object's state to another object.
- default copy constructor performs a shallow copy.
- user-defined copy constructor can perform deep copy if needed.
- invoked when an object is initialized from another object of the same class.
- user defined implementattion is needed for pointer members to avoid shallow
copy issues.
- syntax:
class ClassName {
public:
  ClassName(const ClassName &other); // copy constructor
};
*/

// class declaration
class Integer {
private:
  int *m_pInt;

public:
  Integer();
  Integer(int v);
  int getValue() const;
  void setValue(int v);
  ~Integer();
};

// class definition
Integer::Integer() { m_pInt = new int(0); }
Integer::Integer(int v) { m_pInt = new int(v); }
int Integer::getValue() const { return *m_pInt; }
void Integer::setValue(int v) { *m_pInt = v; }
Integer::~Integer() { delete m_pInt; }

int main() {
  Integer num1(42);    // normal constructor
  Integer num2 = num1; // copy constructor invoked

  std::cout << "num1: " << num1.getValue() << std::endl;
  std::cout << "num2: " << num2.getValue() << std::endl;

  num2.setValue(100); // modifying num2

  std::cout << "After modifying num2:" << std::endl;
  std::cout << "num1: " << num1.getValue()
            << std::endl; // num1 should remain unchanged
  std::cout << "num2: " << num2.getValue() << std::endl;

  return 0;
}