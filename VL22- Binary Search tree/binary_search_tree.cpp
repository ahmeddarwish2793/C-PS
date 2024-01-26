#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

template <class T>
class BSTNode {
 public:
  BSTNode(T const& x) : left_{nullptr}, cont_{x}, right_{nullptr} {}

  BSTNode* left_;
  T cont_;
  BSTNode* right_;
};

template <class T>
class BST {
  BSTNode<T>* root_;  // the root_ of the tree
  int size_;          // stores number of items
 public:
  BST() : root_{nullptr}, size_{0} {}

  int size() const { return size_; }

  // return height of the tree:
  int get_height() { return get_height(root_); }

  // insert new element x into this tree as a new leaf
  void insert(T const& x) {
    root_ = insert(x, root_);
    ++size_;
  }

 private:
  int get_height(BSTNode<T>* node) {
    if (node == nullptr) return 0;  // leerer (Teil)baum

    int linke_TB_Hoehe = get_height(node->left_);
    int rechte_TB_Hoehe = get_height(node->right_);

    // gib Maximum der beiden Teilbaumenhoehen (+1) zurueck:
    if (linke_TB_Hoehe > rechte_TB_Hoehe)
      return linke_TB_Hoehe + 1;
    else
      return rechte_TB_Hoehe + 1;
  }

  // recursive insert into BST; return ptr to either new node or current
  BSTNode<T>* insert(T const& x, BSTNode<T>* current) {
    if (current == nullptr) {
      // base case: create node and return pointer to it
      return new BSTNode<T>(x);
    }

    // recursive case: compare x with current->cont and go left/right
    if (x < current->cont_)
      current->left_ = insert(x, current->left_);
    else
      current->right_ = insert(x, current->right_);
    return current;  // return pointer to passed pointer
  }
};

int main() {
  BST<string> dictionary;

  ifstream myfile;
  myfile.open("wordlist-german_shuffled.txt");
  for (std::string line; getline(myfile, line);) {
    if (line.length() == 3) {
      dictionary.insert(line);
    }
  }
  printf("# Woerter mit Laenge 3 ist %i\n", dictionary.size());
  printf("Hoehe des Baums ist %i\n", dictionary.get_height());
}
