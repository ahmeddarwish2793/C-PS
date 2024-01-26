template <typename T>
class Node {
 public:
  Node(T const& x) : cont_{x} {}
  T cont_;  // speichert das Datenelement
  Node* next_ = nullptr;
};

template <typename T>
class LinkedList {
 public:
  LinkedList() : head_{nullptr} {}

  bool is_empty() { return head_ == nullptr; }

  void push_front(T const& x) {
    Node<T>* new_node = new Node<T>(x);  // erzeuge neue Knoten mit Inhalt x
    new_node->next_ = head_;  // der neue Knoten zeigt auf den bisher ersten...
    head_ = new_node;         // ... und ist der neue erste Knoten
  }

 private:
  Node<T>* head_;  // Beginn der Liste
};