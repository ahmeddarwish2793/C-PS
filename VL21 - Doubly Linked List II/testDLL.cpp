#include <cstdio>
#include <string>

#include "DoublyLinkedList.hpp"

int main() {
  DoublyLinkedList<std::string> spotify_queue;

  // User fügte Lieder in die Warteschlange ein:
  spotify_queue.push_back("Personal Jesus");
  spotify_queue.push_back("A Million Smiles");
  spotify_queue.push_back("Wildbery Lillit");

  std::string letztes_lied = spotify_queue.pop_back();

  DLLNode<std::string>* ptr = spotify_queue.find("Personal Jesus");
  if (ptr) spotify_queue.insert_after(ptr, "Last XMas");

  // Spotify spielt ab:
  for (DLLNode<std::string> const* current = spotify_queue.begin();
       current != nullptr; current = current->next_) {
    //    current->cont_ = "xxx"; // das geht nicht
    printf("%s\n", current->cont_.c_str());
  }
}