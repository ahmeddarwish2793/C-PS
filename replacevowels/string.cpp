#include <cstdio>
#include <string>

using namespace std;
int main () {
    string name = "Ahmed";
    int length = name.length();
    for(int i = 0; i < length; ++i) {
        printf("%c\n",name.at(i));
    }
    printf("the string is: %s\n length: %i",name,length);
}