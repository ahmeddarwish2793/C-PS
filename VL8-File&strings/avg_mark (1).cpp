#include <cstdio>

// compute the average of marks[0,n-1]:
float average_mark(float marks[], int n) {
  float sum = 0.0;  // accumulator for sum of values
  for (int i = 0; i < n; ++i) {
    sum += marks[i];
  }
  return sum / n;  // compute average and return it
}

int count_lines(FILE* file) {
  rewind(file);  // gehe zurück zum Anfang der Datei
  int lines = 0;
  char zeichen;
  while (!feof(file)) {  // solange nicht am Dateiende wiederhole
    zeichen = fgetc(file);
    if (zeichen == '\n') ++lines;  // falls zeichen ein newline ('\n')
  }
  return lines;
}

int main() {
  int num_students;  // Anzahl Studierenden = #Noten

  FILE* my_file = fopen("../../test2.txt", "r");  // versuche, Datei zu oeffnen
  if (my_file == nullptr)
    return 0;  // falls Datei nicht geoeffnet werden konnte

  num_students = count_lines(my_file);
  printf("Es gibt %i Abgaben\n", num_students);

  float* noten = new float[num_students];  // allokiere ausreichend Speicher

  // go through file once again and read the marks:
  rewind(my_file);
  for (int i = 0; i < num_students; ++i) {
    fscanf(my_file, "%f", &noten[i]);
  }

  fclose(my_file);  // close the file

  float avg = average_mark(noten, num_students);

  printf("Die Durchschnittspunktzahl ist %1.1f .\n", avg);
}