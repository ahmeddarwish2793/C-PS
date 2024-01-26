#include <cstdio>

#include "LinkedList.hpp"
#include "String.hpp"

template <typename T>
class Queue {
  LinkedList<T> ll_;

 public:
  void push_back(T x) { ll_.push_back(x); }
  T pop_front() { return ll_.pop_front(); }
  bool is_empty() { return ll_.is_empty(); }
};

int main() {
  Queue<MyString> spotify_queue;

  // User fügte Lieder in die Warteschlange ein:
  spotify_queue.push_back("Personal Jesus");
  spotify_queue.push_back("A Million Smiles");
  spotify_queue.push_back("Wildbery Lillit");

  // Spotify spielt ab:
  while (spotify_queue.is_empty() == false) {
    MyString naechstes_lied = spotify_queue.pop_front();
    printf("spiele Lied %s\n", naechstes_lied.c_str());
  }
}