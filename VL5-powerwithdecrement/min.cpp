#include <cstdio>

int min(int x, int y);  // Funktionsdeklaration

// drucke das Minimum von 2 Werten:
void print_min(int a, int b) { printf("Das Minimum ist %i\n", min(a, b)); }

int main() {
  int a = 5;
  int b = -3;
  print_min(a, b);
  return 0;
}

int min(int x, int y) {
  if (x < y) return x;
  return y;
}
