#include <cstdio>

void print_all(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%i,", array[i]);
  }
  printf("\n");
  ++array[0];
}

int main() {
  int array[3] = {1, 2, 3};

  printf("%p\n", &array);  // print address of array[0]

  print_all(array, 3);
  print_all(array, 3);
}