#include <cstdio>

// return true iff the 2 strings have the same contents:
bool str_equal(char const str1[], char const str2[]) {
  for (int i = 0; str1[i] == str2[i]; ++i) {
    if (str1[i] == 0) return true;  // dann ist auch str2[i]=0, also gleich!
  }
  return false;
}

int main() {
  char* name1 =
      new char[1000];  // name1 ist ZEIGER auf den Beginn von 1000 chars
  printf("Spieler/in 1 Name: ");
  scanf("%s", name1);

  char* name2 =
      new char[1000];  // name1 ist ZEIGER auf einen ANDEREN Speicherbereich
  printf("Spieler/in 2 Name: ");
  scanf("%s", name2);

  if (str_equal(name1, name2)) {  // vergleiche nur die Zeiger
    printf("Es müssen unterschiedliche Namen eingegeben werden!\n");
    return 0;
  }
}