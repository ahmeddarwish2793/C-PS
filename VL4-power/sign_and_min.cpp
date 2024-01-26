#include <cstdio>

unsigned char sign(int n) {
  if (n < 0) {   // teste, ob n < 0 ist und führe folgenden Block nur dann aus
    return '-';  // return beendet die Ausführung der Funktion
  }
  return '+';  // wird zurückgegen, falls nicht vorher '-' zurückgegeben wurde
}

// gib das Minimum von 2 Zahlen zurück
int min(int zahl1, int zahl2) {
  if (zahl1 <= zahl2) {
    return zahl1;
  } else {
    return zahl2;
  }
}

int main() {      // diese Zeile braucht jedes C++-Programm, weil Einsprungpunkt
  int eine_zahl;  // snake_case style
  int noch_eine_zahl;

  // Eingabe einer Zahl:
  printf("Welche Zahl moechten Sie eingeben?\n");
  scanf("%i", &eine_zahl);
  printf("Welche Zahl moechten Sie noch eingeben?\n");
  scanf("%i", &noch_eine_zahl);

  // Ausgabe des Ergebnis:
  printf("Das Minimum der beiden Zahlen ist %i\n",
         min(eine_zahl, noch_eine_zahl));
}