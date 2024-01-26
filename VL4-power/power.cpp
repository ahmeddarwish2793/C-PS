// die folgende Zeile immer, wenn Ausgabe von Text gewünscht ist:
#include <cstdio>

// gib n^x zurück ("n hoch x")
int power(int n, unsigned int x) {
  int r = 1;  // das wird der zurückgegebene Wert sein
  int w = x;  // Hilfsvariable für Anzahl der Wiederholungen

  while (w > 0) {
    r = r * n;  // multipliziere n mit bisherigen Wert; Ergebnis in r
    w = w - 1;  // erniedrige w um 1
  }
  return r;
}

int main() {  // diese Zeile braucht jedes C++-Programm, weil Einsprungpunkt
  int basis;  // snake_case style
  int exponent;

  // Eingabe einer Zahl:
  printf("Basis = ");
  // die folgende Zeile genau so verwenden, um einen Wert einzulesen und
  // den eingelesenen Wert in n zu speichern:
  scanf("%i", &basis);
  printf("Exponent = ");
  scanf("%i", &exponent);

  if (exponent < 0) {
    printf("Ich kann keine negativen Exponenten verarbeiten!\n");
    return -1;  // Fehlercode zurückgeben; main() abbrechen
  }

  // Ausgabe des Ergebnis:
  printf("%i hoch %i ist %i.\n", basis, exponent, power(basis, exponent));
}