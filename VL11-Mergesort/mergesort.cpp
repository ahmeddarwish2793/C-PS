#include "printall.hpp"

void merge(int a[], int b[], int l) {
  int left = 0;   // Index in a[0,l-1]
  int right = 0;  // Index in b[0,l-1]

  int* c = new int[2 * l];  // allokiere ein array c[0,2l-1]
  int idx;                  // Index in c[0,2l-1]

  for (idx = 0; left < l && right < l; ++idx) {
    if (a[left] < b[right]) {
      c[idx] = a[left];  // Minimum ist in a
      ++left;            // gehe 1 Position weiter in a
    } else {
      c[idx] = b[right];  // Minimum ist in b
      ++right;            // gehe 1 Position weiter in b
    }
  }

  if (left < l) {  // es gibt noch Werte in a
    while (idx < 2 * l) {
      c[idx] = a[left];
      ++idx;
      ++left;
    }
  } else {
    while (idx < 2 * l) c[idx++] = b[right++];  // Kurzschreibweise
  }

  print_all(c, 2 * l);
  delete[] c;
}

int main() {
  int array1[] = {5, 7, 9, 13};
  int array2[] = {1, 8, 14, 27};
  merge(array1, array2, 4);
}