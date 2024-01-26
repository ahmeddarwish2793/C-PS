#include <random>

#include "min.hpp"
#include "printall.hpp"

// merge 2 sortierte Arrays a[0,la-1] und b[0,lb-1]
// und schreibe das Ergebnis in c[0,la+lb-1]
void merge(int const a[], int const b[], int c[], int la, int lb) {
  int left = 0;   // Index in a[0,la-1]
  int right = 0;  // Index in b[0,lb-1]

  int idx;  // Index in c[0,la+lb-1]

  for (idx = 0; left < la && right < lb; ++idx) {
    if (a[left] < b[right]) {
      c[idx] = a[left];  // Minimum ist in a
      ++left;            // gehe 1 Position weiter in a
    } else {
      c[idx] = b[right];  // Minimum ist in b
      ++right;            // gehe 1 Position weiter in b
    }
  }

  if (left < la) {  // es gibt noch Werte in a
    while (idx < la + lb) {
      c[idx] = a[left];
      ++idx;
      ++left;
    }
  } else {
    while (idx < la + lb) c[idx++] = b[right++];  // Kurzschreibweise
  }
}

// sortiere das array[0,n-1] aufsteigend mit mergesort:
void merge_sort(int array[], int n) {
  int* tmp = new int[n];  // allokiere temporären Platz
  for (int l = 1; l < n; l = l * 2) {
    // an dieser Stelle sind alle Teilarrays array[0,l-1], array[l,2l-1],
    // array[2l,3l-1], usw sortiert!
    for (int s = 0; s + l < n; s = s + 2 * l) {
      int length_b = min(l, n - s - l);  // um nicht aus dem Array rauszufallen

      // array+s bezeichnet array[s,...]
      merge(array + s, array + s + l, tmp, l, length_b);
      // jetzt enthält tmp die Werte aus array[s,s+l-1] und array[s+l,
      // s+l+length_b-1]

      // kopiere diese zurück in array:
      for (int i = 0; i < l + length_b; ++i) array[s + i] = tmp[i];
      // jetzt sind alle Teilarrays array[0,2l-1], array[2l,4l-1] usw. sortiert
    }
  }
  delete[] tmp;
}

// gibt Position des Minimums in array[j,length-1] zurück:
int min_pos(int array[], int length, int j) {
  int min_pos_so_far = j;  // position of smallest elt. seen so far
  for (int i = j + 1; i < length; ++i) {
    if (array[i] < array[min_pos_so_far]) min_pos_so_far = i;
  }
  return min_pos_so_far;
}
// sortiere das Array - das gleiche wie x_th_smallest(array, length, n),
// nur ohne Rückgabewert (dies heißt "selection sort" - Sortieren durch
// Auswahl):
void selection_sort(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    // find minimum in array[i,length-1]:
    int j = min_pos(array, length, i);

    // swap array[i] with array[j]
    int tmp = array[i];   // sichere den Wert array[i] vor dem Überschreiben
    array[i] = array[j];  // überschreibt den Wert array[i] mit array[j]
    array[j] = tmp;  // schreibe den ursprünglichen Wert array[i] nach array[j]
  }
}

int main() {
  int n = 100000000;
  int* array = new int[n];
  std::random_device r;  // erzeuge Zufallszahlengenerator

  // fülle array mit zufälligen Zahlen aus [0,999]:
  for (int i = 0; i < n; ++i) array[i] = r() % 1000;

  // sortiere array:
  merge_sort(array, n);
}