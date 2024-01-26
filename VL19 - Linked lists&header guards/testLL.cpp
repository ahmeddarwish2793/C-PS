#include <chrono>
#include <cstdio>

#include "LinkedList.hpp"
#include "StackResArr.hpp"
#include "String.hpp"  // inkludiert ResizableArray ein 2. Mal!!

typedef MyString string;  // string ist jetzt ein Alias für MyString

template <typename T>
class StackLL {
 public:
  StackLL() : stack_() {}

  void push(T const& x) { stack_.push_front(x); }

  T pop() { return stack_.pop_front(); }

  bool is_empty() const { return stack_.is_empty(); }

 private:
  LinkedList<T> stack_;
};

int main() {
  // StackLL<string> stack;
  // stack.push(string("Johannes"));
  // stack.push("Peter");  // wie die Zeile darüber, aber mit automatischen
  //                       // Konstruktoraufruf
  // stack.push("Christian");

  // //  printf("%s\n", stack[2].c_str());

  // while (!stack.is_empty()) {
  //   string name = stack.pop();
  //   printf("%s\n", name.c_str());
  // }

  MyStack<int> stack;

  for (int i = 0; i < 250000; ++i) {
    auto start = std::chrono::system_clock::now();  // aktuelle Zeit
    stack.push(i);
    auto end = std::chrono::system_clock::now();  // aktuelle Zeit
    std::chrono::microseconds time =
        end - start;  // berechne Zeit fuer die push-Op

    printf("%lld\n", time.count());
  }
}