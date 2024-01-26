template <typename U>
class Node {
 public:
  Node(U const& x) : cont_{x} {}
  U cont_;  // speichert das Datenelement
  Node* next_ = nullptr;
};

template <typename T>
class LinkedList {
 public:
  LinkedList() : head_{nullptr} {}

  bool is_empty() const { return head_ == nullptr; }

  void push_front(T const& x) {
    Node<T>* new_node = new Node<T>(x);  // erzeuge neue Knoten mit Inhalt x
    new_node->next_ = head_;  // der neue Knoten zeigt auf den bisher ersten...
    head_ = new_node;         // ... und ist der neue erste Knoten
  }

  // loescht das erste Element aus der LinkedList:
  T pop_front() {
    if (!is_empty()) {
      Node<T>* tmp = head_->next_;     // temporäre Kopie des Zeigers
      T first_element = head_->cont_;  // erzeugt eine Kopie
      delete head_;  // loescht das Knotenobjekt (das irgendwann mal in
                     // push_front angelegt wurde)

      head_ = tmp;
      return first_element;  // erzeugt Kopie, da keine Referenz zurückgegeben
    }
    return T();  // damit irgendwas zurückgegeben wird
  }

  // Index-Operator als Referenz:
  T& operator[](int i) {
    Node<T>* current = head_;  // kopiere Zeiger auf head_
    for (int j = 0; j < i; ++j) current = current->next_;  // folge i-mal next_
    return current->cont_;
  }

  ~LinkedList() {
    while (!is_empty()) pop_front();  // loescht alle Knotenobjekte aus der LL
  }

 private:
  Node<T>* head_;  // Beginn der Liste
};