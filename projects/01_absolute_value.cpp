#include <cstdio>

int absolute_value(int number) { return (number < 0) ? -1 * number : number; }

int main() {
  int num1 = -5;
  int num2 = 5;

  printf("Absolute value of %d is %d\n", num1, absolute_value(num1));
  printf("Absolute value of %d is %d\n", num2, absolute_value(num2));

  return 0;
}