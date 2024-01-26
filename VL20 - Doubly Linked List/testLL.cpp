#include <chrono>
#include <cstdio>

#include "LinkedList.hpp"
#include "StackResArr.hpp"
#include "String.hpp"  // inkludiert ResizableArray ein 2. Mal!!

typedef MyString string;  // string ist jetzt ein Alias für MyString

template <typename T>
class StackLL {
 public:
  StackLL() : ll_() {}

  void push(T const& x) { ll_.push_front(x); }

  T pop() { return ll_.pop_front(); }

  bool is_empty() const { return ll_.is_empty(); }

 private:
  LinkedList<T> ll_;
};

int main() {
  LinkedList<string> ll;
  ll.push_front(string("Johannes"));
  ll.push_front("Peter");  // wie die Zeile darüber, aber mit automatischen
                           // Konstruktoraufruf
  ll.push_front("Christian");

  //  printf("%s\n", ll[2].c_str());

  for (int i = 0; i < ll.size(); ++i) {
    string name = ll[i];
    printf("%s\n", name.c_str());
  }
}