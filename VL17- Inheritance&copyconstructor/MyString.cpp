#include <cstring>

#include "ResizableArray.hpp"

class MyString : public ResizableArray<char> {
 public:
  // Konstruktor, der aus einem gegebenen c-String ein neues Objekt erzeugt:
  MyString(char const* c_str = "")
      : ResizableArray(strlen(c_str) +
                       1) {  // ruft Konstruktor der Oberklasse auf
    for (int i = 0; c_str[i] != '\0'; ++i)
      push_back(c_str[i]);  // Zeichen kopieren
  }

  void append(char const* c_str) {
    for (int i = 0; c_str[i] != '\0'; ++i) push_back(c_str[i]);
  }
};

int main() {
  MyString s1("www.tagesschau.de/");
  s1.append(
      "nachrichten_20uhr/");  // s1 = "www.tagesschau.de/nachrichten_20uhr/"

  for (int i = 0; i < s1.size(); ++i) printf("%c", s1[i]);
  printf("\n");

  MyString s2("");  // das würde versuchen, Speicher der Länge 0 zu allokieren
                    // (im Konstruktor von ResizableArray)
  MyString s3;
}