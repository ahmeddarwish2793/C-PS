#include <climits>
#include <cstdio>
#include <random>

#include "ResizableArray.hpp"

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

int main() {
  ResizableArray<Stud>
      studierende;  // erstelle neues Objekt vom Typ ResizableArray
  studierende.push_back(Stud(12345, 4.0, 'm'));
  studierende.push_back(Stud(23456, 1.0, 'f'));
  studierende.push_back(Stud(34567, 2.3, 'm'));
  studierende.push_back(Stud(45678, 2.0, 'f'));

  ResizableArray<Stud> k = studierende;  // erzeuge Kopie von studierende
  ResizableArray<Stud> k2(
      studierende);  // syntaktisch äquivalent zur Zeile darüber

  ResizableArray<Stud>
      k3;            // ruft den Standard-Konstruktor von ResizableArray auf
  k3 = studierende;  // ist nicht das gleiche wie Zeile 30, sondern ruft den
                     // Kopier-Zuweisungsoperator auf

  // // prüfe,ob der 3. Eintrag von studierende = Stud(45678, 2.0, 'f') ist:
  // Stud thomas(45678, 2.1, 'f');
  // if (studierende[3].is_equal(thomas)) printf("gleich\n");

  k3[1].matr_nr_ = 000;

  for (int i = 0; i < studierende.size(); ++i)
    printf("(%i, %f, %c),", studierende[i].matr_nr_, studierende[i].note_,
           studierende[i].gender_);
  printf("\n");

  for (int i = 0; i < k.size(); ++i)
    printf("(%i, %f, %c),", k[i].matr_nr_, k[i].note_, k[i].gender_);
  printf("\n");

  for (int i = 0; i < k3.size(); ++i)
    printf("(%i, %f, %c),", k3[i].matr_nr_, k3[i].note_, k3[i].gender_);
  printf("\n");
}