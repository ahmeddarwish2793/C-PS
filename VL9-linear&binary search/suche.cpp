#include <cstdio>

#include "io.hpp"

// entscheide, ob x in array[0,length-1] vorkommt (lineare Suche):
bool find(int const array[], int length, int x) {
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
  FILE* my_file =
      fopen("../../tn_sorted.csv", "r");  // versuche, Datei zu oeffnen
  if (my_file == nullptr)
    return 0;  // falls Datei nicht geoeffnet werden konnte

  // berechne #Matrikelnummern:
  int num_students = count_lines(my_file);
  printf("%i Matrikelnummern gelesen...\n", num_students);

  int* nummern = new int[num_students];  // allokiere ausreichend Speicher

  // lies die Matrikelnummern aus der Datei ein und speichere sie in nummern[]:
  rewind(my_file);
  for (int i = 0; i < num_students; ++i) {
    fscanf(my_file, "%i", &nummern[i]);
  }
  fclose(my_file);  // close the file

  // Hauptprogramm: warte wiederholt auf Eingabe einer Matrikelnr.
  // und suche sie in der oben eingelesenen Liste:
  int zu_suchende_nr;
  while (scanf("%i", &zu_suchende_nr)) {
    if (find_faster(nummern, num_students, zu_suchende_nr)) {
      printf("Die Nummer ist vorhanden.\n");
    } else {
      printf("Die Nummer ist NICHT vorhanden.\n");
    }
  }

  // Laufzeittest:
  // for (int i = 0; i < 500000; ++i) {
  //   find_faster(nummern, num_students, i);
  // }

  // für die Templatisierung:
  float noten[] = {2.7, 1.0, 1.0, 2.3, 5.0};
  find_faster(noten, 5, (float)4.0);
}