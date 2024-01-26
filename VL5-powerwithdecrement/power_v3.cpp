// die folgende Zeile immer, wenn Ausgabe von Text gewünscht ist:
#include <cstdio>

// gib n^x zurück ("n hoch x")
int pow(int n, int x) {
  int ergebnis = 1;  // das wird der zurückgegebene Wert sein

  while (x > 0) {
    ergebnis *= n;  // kurz für ergebnis = ergebnis * n
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
    return 23;  // Fehlercode zurückgeben; main() abbrechen
  }

  // Ausgabe des Ergebnis:
  int ergebnis = pow(basis, exponent);
  printf("%i hoch %i ist %i.\n", basis, exponent, ergebnis);
}