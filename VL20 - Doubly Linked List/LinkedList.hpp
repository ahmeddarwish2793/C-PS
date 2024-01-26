template <typename U>
class Node {
 public:
  Node(U const& x) : cont_{x} {}
  U cont_;  // speichert das Datenelement
  Node* next_ = nullptr;
};

template <typename T>
class LinkedList {
  Node<T>* head_;  // Beginn der Liste
  Node<T>* last_;  // Ende der Liste
  int size_;       // #der Elemente in der Liste sein

 public:
  LinkedList() : head_{nullptr}, last_{nullptr}, size_{0} {}

  // copy constructor: s. Quiz VL 20 Folie 18
  LinkedList(LinkedList const& other) : head_{nullptr}, n_{0}, last_{nullptr} {
    for (LLNode<T>* current = other.head_; current != nullptr;
         current = current->next_) {
      push_back(current->cont_);  // pushing to back to remain order
    }
  }

  // Kopierzuweisungsoperator -- not covered in lecture:
  LinkedList& operator=(LinkedList const& other) {
    while (!is_empty()) pop_front();  // empty myself
    for (LLNode<T>* current = other.head_; current != nullptr;
         current = current->next_) {
      push_back(current->cont_);  // pushing to back to remain order
    }
    return *this;
  }

  bool is_empty() const { return head_ == nullptr; }

  void push_front(T const& x) {
    Node<T>* new_node = new Node<T>(x);  // erzeuge neue Knoten mit Inhalt x
    new_node->next_ = head_;  // der neue Knoten zeigt auf den bisher ersten...
    if (is_empty())
      last_ = new_node;  // falls in leere Liste eingefügt, dann last_ setzen
    head_ = new_node;    // ... und ist der neue erste Knoten
    ++size_;
  }

  // loescht das erste Element aus der LinkedList:
  T pop_front() {
    if (!is_empty()) {
      Node<T>* tmp = head_->next_;     // temporäre Kopie des Zeigers
      T first_element = head_->cont_;  // erzeugt eine Kopie
      delete head_;  // loescht das Knotenobjekt (das irgendwann mal in
                     // push_front angelegt wurde)

      head_ = tmp;
      if (is_empty()) last_ = nullptr;
      --size_;
      return first_element;  // erzeugt Kopie, da keine Referenz zurückgegeben
    }
    return T();  // damit irgendwas zurückgegeben wird
  }

  void push_back(T x) {
    Node<T>* new_node = new Node<T>(x);  // erzeuge neue Knoten mit Inhalt x
    new_node->next_ = nullptr;  // der neue Knoten ins nichts, da am Ende
    if (is_empty())
      head_ = new_node;  // falls in leere Liste eingefügt, dann head_ setzen
    else
      last_->next_ = new_node;
    last_ = new_node;  // ... und ist der neue erste Knoten
    ++size_;
  }

  // Index-Operator als Referenz:
  T& operator[](int i) {
    Node<T>* current = head_;  // kopiere Zeiger auf head_
    for (int j = 0; j < i; ++j) current = current->next_;  // folge i-mal next_
    return current->cont_;
  }

  int size() { return size_; }

  ~LinkedList() {
    while (!is_empty()) pop_front();  // loescht alle Knotenobjekte aus der LL
  }
};