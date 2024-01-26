#include "printall.hpp"

int main() {
  int array[100] = {};

  print_all(array, 100);

  array[0] = 42;
  print_all(array, 100);

  return 0;
}