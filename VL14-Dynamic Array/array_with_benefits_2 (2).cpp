#include <cstdio>

template <typename T>
class Array {
 public:  // kann von ausserhalb der Klasse gelesen/zugegriffen werden
  // Konstruktor für ein Array vom Typ T: lege Array der Groesse size an und
  // fuelle alle Eintraege mit dem Wert init
  Array(int size = 1, T init = 0) : n_{size} {
    // n_ = size; // nicht noetig wegen n_{size}
    array_ = new T[n_];  // allokiert Speicher
    for (int i = 0; i < n_; ++i) array_[i] = init;
  }

  // Destruktor: wird beim "Zerstoeren" des Objekts aufgerufen
  ~Array() {
    delete[] array_;  // gib Speicher wieder frei
  }

  void copy_array(int const c_array[]) const {
    for (int i = 0; i < n_; ++i) array_[i] = c_array[i];
  }

  T read(int i) const {
    if (i < 0 || i > n_ - 1) return 0;  // index out of bounds
    return array_[i];
  }

  void write(int i, T x) {
    if (i < 0 || i > n_ - 1) return;
    array_[i] = x;  // speichere an der Stelle i den Wert x
  }

 private:     // kann nicht von ausserhalb der Klasse gelesen werden:
  int n_;     // Groesse des Arrays (Anzahl der Elemente)
  T* array_;  // Zeiger auf das Array an sich
};

int main() {
  int const n = 20;
  Array<float> noten(n, 5.0);  // erzeugt ein Objekt "noten" vom Typ "Array"
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