#include <cstdio>
#include <string>
using namespace std;


string replace(const string &s)
{
  string answer;
  for(int i = 0; i < s.length(); ++i) {
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
       s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
      answer += '!';
    else answer += s[i];     
  }  
  
  return answer; //coding and coding....
}