#include <cstdio>

template <typename T>
class Array {
 public:  // kann von ausserhalb der Klasse gelesen/zugegriffen werden
  // Konstruktor für ein Array der Groesse size und fuelle alle Eintraege mit
  // dem Wert init
  Array(int size = 20, T init = 0) : n_{size} {
    // n_ = size; // nicht noetig wegen n_{size}
    array_ = new T[n_];  // allokiert Speicher
    for (int i = 0; i < n_; ++i) array_[i] = init;
  }

  // Destruktor: wird beim "Zerstren" des Objekts aufgerufen
  ~Array() {
    delete[] array_;  // gib Speicher wieder frei
  }

  T read(int i) {
    if (i < 0 || i > n_ - 1) return 0;  // index out of bounds
    return array_[i];
  }

  void write(int i, T x) {
    if (i < 0 || i > n_ - 1) return;
    array_[i] = x;  // speichere an der Stelle i den Wert x
  }

 private:     // kann nicht von ausserhalb der Klasse gelesen werden:
  int n_;     // Groesse des Arrays (Anzahl der Elemente)
  T* array_;  // das Array an sich
};

int main() {
  int x;                        // erzeugt ein Objekt "x" vom Typ "int"
  Array<float> noten(20, 5.0);  // erzeugt ein Objekt "noten" vom Typ "Array"
  Array<int> matr_nr(
      20);  // ruft den Konstruktor mit dem Standard-Initialisierungswert auf

  Array<char> gender;  // ruft den Konstruktor mit beiden Standardwerten auf

  noten.write(5, 1.0);  // analog zu noten[5] = 1.0;
  matr_nr.write(5, 12345);
  gender.write(5, 'f');

  for (int i = 0; i < 20; ++i) {
    printf("(%i, %f, %c)\n", matr_nr.read(i), noten.read(i), gender.read(i));
  }
  printf("\n");
}