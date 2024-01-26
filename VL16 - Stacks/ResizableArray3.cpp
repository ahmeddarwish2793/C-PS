#include <climits>
#include <cstdio>
#include <random>

#include "ResizableArray.hpp"

// das ist gut, da Referenzen verwendet werden:
template <typename T>
T min_in_array_ref(ResizableArray<T> const& a) {
  T min_so_far = a[0];
  for (int i = 1; i < a.size(); ++i)
    if (a[i] < min_so_far) min_so_far = a[i];
  return min_so_far;
}

// zeigerbasierte Version von min_in_array -- das funktioniert:
template <typename T>
T min_in_array_ptr(ResizableArray<T>* pta) {  // pta = pointer to array
  T min_so_far = (*pta)[0];  // * ist hier der Dereferenzierunsoperator
  for (int i = 1; i < pta->size(); ++i)
    if ((*pta)[i] < min_so_far) min_so_far = (*pta)[i];
  return min_so_far;
}

int main() {
  std::random_device rd;
  ResizableArray<int> zahlen;
  for (int i = 0; i < 10000; ++i) zahlen.push_back(rd() % INT_MAX);
  zahlen.write(25, -111111);  // moechte zahlen[25] = -111111; schreiben
  zahlen[25] = -111112;
  int min = min_in_array_ptr(&zahlen);
  printf("die kleinste Zahl ist %i\n", min);
}