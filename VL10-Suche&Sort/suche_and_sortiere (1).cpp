#include <cstdio>

#include "io.hpp"
#include "printall.hpp"

// gibt Position des Minimums in array[j,length-1] zurück:
int min_pos(int array[], int length, int j) {
  int min_pos_so_far = j;  // position of smallest elt. seen so far
  for (int i = j + 1; i < length; ++i) {
    if (array[i] < array[min_pos_so_far]) min_pos_so_far = i;
  }
  return min_pos_so_far;
}

// gibt Pos. der zweitkleinsten Wertes in array[j,length-1] zurück:
int second_smallest(int array[], int length) {
  int j = min_pos(array, length, 0);  // Minimum im ganzen Array

  // swap array[0] with array[j]
  int tmp = array[0];   // sichere den Wert array[0] vor dem Überschreiben
  array[0] = array[j];  // überschreibt den Wert array[0] mit array[j]
  array[j] = tmp;  // schreibe den ursprünglichen Wert array[0] nach array[j]

  int second_smallest_pos =
      min_pos(array, length, 1);  // Minimum ab Pos. 1 im Array
  return array[second_smallest_pos];
}

// gibt Pos. der drittkleinsten Wertes in array[j,length-1] zurück:
int third_smallest(int array[], int length) {
  int j = min_pos(array, length, 0);  // Minimum im ganzen Array

  // swap array[0] with array[j]
  int tmp = array[0];   // sichere den Wert array[0] vor dem Überschreiben
  array[0] = array[j];  // überschreibt den Wert array[0] mit array[j]
  array[j] = tmp;  // schreibe den ursprünglichen Wert array[0] nach array[j]

  j = min_pos(array, length, 1);  // Minimum ab Pos. 1 im Array
  tmp = array[1];
  array[1] = array[j];
  array[j] = tmp;

  int third_smallest_pos = min_pos(array, length, 2);
  return array[third_smallest_pos];
}

// return the x'th smallest elt. in array[0,length-1]:
int x_th_smallest(int array[], int length, int x) {
  for (int i = 0; i < x; ++i) {
    // find minimum in array[i,length-1]:
    int j = min_pos(array, length, i);

    // swap array[i] with array[j]
    int tmp = array[i];   // sichere den Wert array[i] vor dem Überschreiben
    array[i] = array[j];  // überschreibt den Wert array[i] mit array[j]
    array[j] = tmp;  // schreibe den ursprünglichen Wert array[i] nach array[j]

    print_all(array, length);
  }
  return array[x - 1];  // dies ist das x-t kleinste Element
}

// sortiere das Array - das gleiche wie x_th_smallest(array, length, n),
// nur ohne Rückgabewert (dies heißt "selection sort" - Sortieren durch
// Auswahl):
void sort(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    // find minimum in array[i,length-1]:
    int j = min_pos(array, length, i);

    // swap array[i] with array[j]
    int tmp = array[i];   // sichere den Wert array[i] vor dem Überschreiben
    array[i] = array[j];  // überschreibt den Wert array[i] mit array[j]
    array[j] = tmp;  // schreibe den ursprünglichen Wert array[i] nach array[j]
  }
}

// entscheide, ob x in array[0,length-1] vorkommt (lineare Suche):
template <typename T, typename U>
bool find(T const array[], int length, U x) {
  for (int i = 0; i < length; ++i) {  // gehe über alle Werte des Arrays
    if (array[i] == x) return true;   // x gefunden
  }
  return false;  // x nicht gefunden
}

// entscheide, ob x im AUFSTEIGEND SORTIERTEN array[0,length-1] vorkommt (binäre
// Suche):
template <typename T>
bool find_faster(T const array[], int length, T x) {
  // left/right: linke/rechte Grenze im noch zu durchsuchenden Array:
  int left = 0, right = length - 1;  // initialisiere

  while (right >= left) {  // solange das Suchintervall noch nicht leer ist
    int middle = (left + right) / 2;  // Mitte des noch durchsuchenden Arrays
    if (x == array[middle]) return true;
    if (x < array[middle])
      right = middle -
              1;  // falls x vorhanden, muss es in array[left,middle-1] sein
    else
      left = middle +
             1;  // falls x vorhanden, muss es in array[middle+1,right] sein
  }
  return false;  // x nicht gefunden => return false
}

int main() {
  FILE* datei;
  datei = fopen("../../tn.csv", "r");
  if (datei != nullptr) {
    int const num_students = count_lines(datei);
    printf("There are %i number of students\n", num_students);
    int* nummern = new int[num_students];  // allocate num_students entries

    for (int i = 0; i < num_students; ++i) {
      fscanf(datei, "%i", &nummern[i]);
    }
    fclose(datei);

    sort(nummern, num_students);  // sortiere Matrikelnummern
    print_all(nummern, num_students);
  }

  // int array[] = {23, 45, 2, 74, 43, 576, 34};
  // printf("Der siebtkleinste Wert ist %i.\n", x_th_smallest(array, 7, 7));

  // return 0;

  // für die Templatisierung:
  // float noten[] = {2.7, 1.0, 1.0, 2.3, 5.0};
  // find(noten, 5, (float)4);  // cast: wandele zur Laufzeit in ein float um
  // find(noten, 5, 4.0f);      // konstante Float-Zahl
  // find(noten, 5,
  //      4);  // unterschiedliche Typen (ruft Funktion bool find(float*, int)
  //      auf)
}