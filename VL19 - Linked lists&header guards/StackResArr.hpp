#ifndef STACK_RES_ARR_HPP
#define STACK_RES_ARR_HPP

#include "ResizableArray.hpp"

template <typename T>
class MyStack {
 public:
  MyStack() : array_(1) {}

  void push(T x) { array_.push_back(x); }
  T pop() { return array_.pop_back(); }
  bool is_empty() { return array_.size() == 0; }

  // gib das oberste Element zurück (aber loesche es nicht):
  T top() {
    T last = array_[array_.size() - 1];
    return last;
  }

 private:
  ResizableArray<T>
      array_;  // die Elemente des Stacks werden in diesem Array gespeichert
};

#endif  // STACK_RES_ARR_HPP