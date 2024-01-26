#include <climits>
#include <cstdio>
#include <random>

template <typename T>
class ResizableArray {
 private:
  int capacity_;  // maximale Kapazität
  T* array_;      // Zeiger auf das C-Array an sich
 public:
  ResizableArray(int initial_capacity = 4)
      : capacity_{initial_capacity}, n_{0} {
    array_ = new T[capacity_];  // allokiere den Speicher für das Array
  }

  ~ResizableArray() { delete[] array_; }

  // füge x am Ende des Arrays ein (verdoppelt evtl. die Kapazität)
  void push_back(T x) {
    if (n_ == capacity_) {
      capacity_ *= 2;                   // verdoppele capacity_
      T* tmp_array = new T[capacity_];  // fordere neuen Speicherbereich an
                                        // (doppelt so gross)
      for (int i = 0; i < n_; ++i)
        tmp_array[i] = array_[i];  // kopiere Elemente
      delete[] array_;  // loesche alten Speicher, da nicht mehr beoetigt
      array_ = tmp_array;
    }
    array_[n_++] = x;  // speichert den Wert x am Ende des Arrays
  }

  T operator[](int i) { return read(i); }  // Indexoperator
  T operator()() {
    printf("Hallo\n");
    return T();
  }  // Klammeroperator sinnlos

  T read(int i) const {
    if (i < 0 || i > n_ - 1) return 0;  // index out of bounds
    return array_[i];
  }

  void write(int i, T x) {
    if (i < 0 || i > n_ - 1) return;
    array_[i] = x;  // speichere an der Stelle i den Wert x
  }

  int n_;  // # Elemente im Array
};

class Stud {
 public:
  Stud(int nr = 0, float note = 5.0f, char gend = 'u')
      : matr_nr_{nr}, note_{note}, gender_{gend} {}

  bool is_equal(Stud other) {
    return matr_nr_ == other.matr_nr_ && note_ == other.note_ &&
           gender_ == other.gender_;
  }

  int matr_nr_;
  float note_;
  char gender_;
};

// das ist schlecht:
template <typename T>
T min_in_array(ResizableArray<T> a) {
  T min_so_far = a[0];
  for (int i = 1; i < a.n_; ++i)
    if (a[i] < min_so_far) min_so_far = a[i];
  return min_so_far;
}

// zeigerbasierte Version von min_in_array -- das funktioniert:
template <typename T>
T min_in_array_ptr(ResizableArray<T>* pta) {  // pta = pointer to array
  T min_so_far = (*pta)[0];  // * ist hier der Dereferenzierunsoperator
  for (int i = 1; i < pta->n_; ++i)
    if ((*pta)[i] < min_so_far) min_so_far = (*pta)[i];
  return min_so_far;
}

int main() {
  std::random_device rd;
  ResizableArray<int> zahlen;
  for (int i = 0; i < 10000; ++i) zahlen.push_back(rd() % INT_MAX);
  int min = min_in_array_ptr(&zahlen);
  printf("die kleinste Zahl ist %i\n", min);

  // ResizableArray<Stud>
  //     studierende;  // erstelle neues Objekt vom Typ ResizableArray
  // studierende.push_back(Stud(12345, 4.0, 'm'));
  // studierende.push_back(Stud(23456, 1.0, 'f'));
  // studierende.push_back(Stud(34567, 2.3, 'm'));
  // studierende.push_back(Stud(45678, 2.0, 'f'));

  // // prüfe,ob der 3. Eintrag von studierende = Stud(45678, 2.0, 'f') ist:
  // Stud thomas(45678, 2.1, 'f');
  // if (studierende[3].is_equal(thomas)) printf("gleich\n");

  // for (int i = 0; i < studierende.n_; ++i)
  //   printf("(%i, %f, %c),", studierende[i].matr_nr_, studierende[i].note_,
  //          studierende[i].gender_);
  // printf("\n");
  // studierende();
}