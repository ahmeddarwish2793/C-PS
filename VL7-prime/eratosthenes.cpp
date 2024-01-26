#include <cassert>
#include <cstdio>

#include "is_prime.hpp"  // inkludiere eine Header-Datei

int main() {
  int constexpr n = 11;  // 'constexpr' heißt, dass der Compiler an dieser
  // Stelle den Wert der Variablen n bestimmen kann (und dieser sich nicht
  // weiter ändert)

  // allokiere den Platz für n bools (ein Array von n bools):
  bool prime[n];  // prime[i] soll true sein, gdw i prim ist

  // // 1. Schritt: initialisiere alle Einträge mit true
  for (int i = 2; i < n; ++i) prime[i] = true;

  // 2. Schritt: besuche die Primzahlen der Reihe nach und
  // setze ihre Vielfachen auf false
  for (int i = 2; i < n; ++i) {
    if (prime[i] == true) {
      assert(is_prime(i));  // nimm an, dass i wirklich prim ist, sonst Abbruch!
      // gib die Primzahl aus:
      printf("%i ", i);
      // besuche alle Vielfachen von i, solange sie kleiner als n sind:
      for (int j = 2; i * j < n; ++j) {
        prime[i * j] =
            false;  // i*j kann keine Primzahl sein, da Vielfaches von i
      }
    }
  }
  printf("\n");
}