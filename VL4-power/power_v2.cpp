// die folgende Zeile immer, wenn Ausgabe von Text gewünscht ist:
#include <cstdio>

// gib n^x zurück ("n hoch x")
int pow(int n, int x) {
  int ergebnis = 1;  // das wird der zurückgegebene Wert sein
 // int zaehler = x;   // Hilfsvariable für Anzahl der Wiederholungen

  while (x > 0) {
    ergebnis = ergebnis * n;  // multipliziere bisheriges Ergebnis mit n
   // zaehler = zaehler - 1;    // erniedrige zaehler um 1
    --x;
  }
  return ergebnis;
}

int main() {
  int basis;
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
  printf("%i hoch %i ist %i.\n", basis, exponent, pow(basis, exponent));
}