#include <cstdio>

void print_all(int const* array,
               int length) {  // wichtig: const direkt hinter int
  for (int i = 0; i < length; ++i) {
    printf("%i,", array[i]);
  }
  printf("\n");
}
