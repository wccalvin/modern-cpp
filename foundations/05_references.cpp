#include <iostream>

/*
 * Reference Type:
 * Defines an alternative name for a variable (an alias)
 * Created using the & operator during declaration
 * Always needs an initializer (referent)
 * referent should be variable
 * it can be used to modify a variable indirectly (like a pointer)
 * reference is NOT a new variable; its just another name (no memory is
 * allocated for a reference)
 */

int main() {
  int x = 7;
  int &ref = x;  // x is referent
  return 0;
}