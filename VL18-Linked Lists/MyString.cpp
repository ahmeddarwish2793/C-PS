#include <cstring>

#include "ResizableArray.hpp"

class MyString : public ResizableArray<char> {
 public:
  // Konstruktor, der aus einem gegebenen c-String ein neues Objekt erzeugt:
  MyString(char const c_str[] = "")
      : ResizableArray(strlen(c_str) +
                       1) {  // ruft Konstruktor der Oberklasse auf
    for (int i = 0; c_str[i] != '\0'; ++i)
      push_back(c_str[i]);  // Zeichen kopieren
    push_back('\0');        // 0-Byte anfügen
  }

  void append(char const* c_str) {
    // in der folgenden Zeile ist "::" der Class-Scope-Operator (der hier
    // nicht nötig wäre, da die Funktion pop_back() nicht überladen ist)
    ResizableArray<char>::pop_back();  // delete '\0'-byte
    for (int i = 0; c_str[i] != '\0'; ++i) push_back(c_str[i]);
    push_back('\0');
  }

  MyString& operator+=(char const* c_str) {  // void-Rückgabewert wäre moeglich
    append(c_str);
    return *this;  // this ist immer ein pointer => dereferenziere ihn!
  }

  MyString operator+(char const* c_str) {
    MyString new_string(*this);  // erzeuge Kopie von mir selbst
    new_string.append(c_str);    // füge c-String an
    return new_string;           // gib alles zurück
  }

  // return C-style string:
  char const* c_str() const { return array_; }
};

int main() {
  MyString s1("www.tagesschau.de/");
  s1.append(
      "nachrichten_20uhr/");  // s1 = "www.tagesschau.de/nachrichten_20uhr/"

  s1 += "eilmeldung/";

  MyString s2 = s1 + "allerneuste_eilmeldung/";

  printf("%s \n", s1.c_str());
  printf("%s \n", s2.c_str());
}