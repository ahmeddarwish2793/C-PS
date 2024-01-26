#include <cstdio>

// gib wahr zurück, gdw. n prim ist:
bool is_prime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;  // gerade Zahl => nicht prim

  // gehe über ungeraden Zahlen bis n^.5 und überprüfe Teilbarkeit:
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;  // Teiler gefunden => nicht prim
  }
  return true;
}
