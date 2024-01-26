// die folgende Zeile immer, wenn Ausgabe von Text gewünscht ist:
#include <cstdio>

int n;  // globale Variablen -- alle haben darafu Zugriff

// berechne das Quadrat von x:
int square(int x) {
  int nsquare;
  nsquare = x * x;
  return nsquare;
}

int main() {  // diese Zeile braucht jedes C++-Programm, weil Einsprungpunkt
  printf("Welche Zahl moechten Sie quadrieren?\n");

  // die folgende Zeile genau so verwenden, um einen Wert einzulesen und
  // den eingelesenen Wert in n zu speichern:
  scanf("%i", &n);

  printf("%i zum Quadrat ist %i.\n", n, square(n));
}