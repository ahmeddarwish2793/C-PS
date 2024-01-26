#include <chrono>

#include "is_prime.hpp"

class ResizableArray {
 private:
  int capacity_;  // maximale Kapazität
  int* array_;    // Zeiger auf das Array an sich
 public:
  ResizableArray(int initial_capacity = 10)
      : capacity_{initial_capacity}, n_{0} {
    array_ = new int[capacity_];  // allokiere den Speicher für das Array
  }

  // füge x am Ende des Arrays ein (verdoppelt evtl. die Kapazität)
  void push_back(int x) {
    if (n_ == capacity_) {
      capacity_ *= 2;                       // verdoppele capacity_
      int* tmp_array = new int[capacity_];  // fordere neuen Speicherbereich an
                                            // (doppelt so gross)
      for (int i = 0; i < n_; ++i)
        tmp_array[i] = array_[i];  // kopiere Elemente
      delete[] array_;  // loesche alten Speicher, da nicht mehr beoetigt
      array_ = tmp_array;
    }
    array_[n_++] = x;  // speichert den Wert x am Ende des Arrays
  }

  int read(int i) const {
    if (i < 0 || i > n_ - 1) return 0;  // index out of bounds
    return array_[i];
  }

  void write(int i, int x) {
    if (i < 0 || i > n_ - 1) return;
    array_[i] = x;  // speichere an der Stelle i den Wert x
  }

  int n_;  // # Elemente im Array
};

int main() {
  ResizableArray my_array;

  // for (int i = 0; i < 1000; ++i)
  //   if (is_prime(i)) my_array.push_back(i);

  // for (int i = 0; i < my_array.n_; ++i) {
  //   printf("%i\n", my_array.read(i));
  // }

  for (int i = 0; i < 250000; ++i) {
    auto start = std::chrono::system_clock::now();  // Zeit vor push_back
    my_array.push_back(i);
    auto end = std::chrono::system_clock::now();  // Zeit nach dem push_back

    std::chrono::microseconds time = end - start;
    printf("%lld\n", time.count());
  }
}