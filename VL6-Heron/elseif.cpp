#include <cassert>
#include <cstdio>

int main() {
  int zahl;
  while (scanf("%i", &zahl) == 1) {
    if (zahl <= 100) {
      assert(zahl <= 100);
      printf("Ihre Zahl ist kleiner als oder gleich 100\n");
    } else {
      if (zahl < 200) {
        assert(zahl > 100 &&
               zahl < 200);  // Programm endet, falls assert nicht zutrifft
        printf("Ihre Zahl ist groesser als 100, aber kleiner als 200\n");
      } else {
        if (zahl < 300) {
          printf("Ihre Zahl ist mindestens 200, aber kleiner als 300\n");
        } else {
          printf("Ihre Zahl ist 300 oder groesser\n");
        }
      }
    }
  }
}