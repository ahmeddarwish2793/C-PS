//Complete the function that takes two integers (a, b, where a < b) and return an array of all integers 
//between the input parameters, including them.

#include <cstdio>
#include <vector>

std::vector<int> between(int start, int end) {
  // your code here
  if(start > end) { 
    printf("not possible");
    return {}; // return an empty vector
    }

  std::vector<int> arr;
  for(int i = start; i <= end; ++i) arr.push_back(i);

  for(int i = 0; i < arr.size(); ++i) {
    printf("%i ", arr[i]);
  }
  return arr;
}  

int main () {
    between (1,4);
}