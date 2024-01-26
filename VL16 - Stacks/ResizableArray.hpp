
// todo: cpy & assgn
template <typename T>
class ResizableArray {
 private:
  int capacity_;  // maximale Kapazität
  T* array_;      // Zeiger auf das C-Array an sich
  int n_;         // # Elemente im Array
 public:
  int size() const { return n_; }  // getter-Methode

  ResizableArray(int initial_capacity = 4)
      : capacity_{initial_capacity}, n_{0} {
    array_ = new T[capacity_];  // allokiere den Speicher für das Array
  }

  ResizableArray(ResizableArray const& other) = delete;

  ~ResizableArray() { delete[] array_; }

  // füge x am Ende des Arrays ein (verdoppelt evtl. die Kapazität)
  void push_back(T x) {
    if (n_ == capacity_) {
      capacity_ *= 2;                   // verdoppele capacity_
      T* new_array = new T[capacity_];  // fordere neuen Speicherbereich an
                                        // (doppelt so gross)
      for (int i = 0; i < n_; ++i)
        new_array[i] = array_[i];  // kopiere Elemente
      delete[] array_;     // loesche alten Speicher, da nicht mehr beoetigt
      array_ = new_array;  // dies kopiert NUR den Zeiger!
    }
    array_[n_++] = x;  // speichert den Wert x am Ende des Arrays
  }

  T pop_back() {
    // Übungsaufgabe!
    return T();
  }

  T& operator[](int i) { return array_[i]; }  // Indexoperator als Referenz
  T const& operator[](int i) const {
    return array_[i];
  }  // Indexoperator als Const-Referenz

  T read(int i) const {
    if (i < 0 || i > n_ - 1) return 0;  // index out of bounds
    return array_[i];
  }

  void write(int i, T x) {
    if (i < 0 || i > n_ - 1) return;
    array_[i] = x;  // speichere an der Stelle i den Wert x
  }
};
