#include <bitset>
#include <cstdio>
using std::bitset;

#include "heap.hpp"

struct Code {
  Code(int l = 0, bitset<64> c = {}) : length_{l}, code_{c} {}
  int length_;
  bitset<64> code_;
};

class HTNode {
 public:
  HTNode(unsigned char letter, int freq) : letter_{letter}, freq_{freq} {}

  ~HTNode() {
    if (left_) delete left_;
    if (right_) delete right_;
  }

  HTNode* left_ = nullptr;
  unsigned char letter_;
  int freq_;
  HTNode* right_ = nullptr;
};

struct HTNodeCompare {
  bool operator()(HTNode const* lhs, HTNode const* rhs) const {
    return lhs->freq_ < rhs->freq_;
  }
};

HTNodeCompare ht_node_cmp;

class HuffmanTree {
 public:
  HuffmanTree(char const* filename) {
    FILE* in_file = fopen(filename, "r");
    compute_frequencies(in_file);

    fclose(in_file);  // close file

    build_ht();  // baue Huffman-Baum

    compute_codes(root_, 1, bitset<64>{});

    // print codes for testing:
    for (int i = 0; i < 256; ++i) {
      if (frequencytable_[i]) {
        printf("%c : ", (unsigned char)i);
        for (int j = 0; j < codetable_[i].length_; ++j) {
          if (codetable_[i].code_[63 - j])
            printf("1");
          else
            printf("0");
        }
        printf("\n");
      }
    }
  }

  // destructor:
  ~HuffmanTree() { delete root_; }

 private:
  int frequencytable_[256] = {};
  Code codetable_[256] = {};  // soll die Codes für Buchstaben enthalten
  HTNode* root_;

  void compute_frequencies(FILE* file) {
    rewind(file);
    for (unsigned char ch = fgetc(file); !feof(file); ch = fgetc(file)) {
      ++frequencytable_[ch];
    }
  }

  void build_ht() {
    PQ<HTNode*, HTNodeCompare> pq(512, ht_node_cmp);
    for (int i = 0; i < 256; ++i) {
      if (frequencytable_[i] > 0) {
        HTNode* new_node = new HTNode((unsigned char)i, frequencytable_[i]);
        pq.push(new_node);
      }
    }

    while (pq.size() > 1) {
      // holen die 2 Knoten mit der niedrigsten Frequency aus der PQ:
      HTNode* left_node = pq.extract_min();
      HTNode* right_node = pq.extract_min();

      HTNode* new_node = new HTNode('_', left_node->freq_ + right_node->freq_);
      new_node->left_ = left_node;
      new_node->right_ = right_node;
      pq.push(new_node);
    }

    root_ = pq.extract_min();
  }

  void compute_codes(HTNode const* node, int depth, bitset<64> code_so_far) {
    if (node->left_ == nullptr && node->right_ == nullptr) {
      // wir sind an einem Blatt
      codetable_[node->letter_] = Code(depth - 1, code_so_far);
    } else {
      // wir sind an einem internen Knoten
      if (node->left_) {
        bitset<64> left_code = code_so_far;
        left_code[64 - depth] = 0;
        compute_codes(node->left_, depth + 1, left_code);
      }
      if (node->right_) {
        bitset<64> right_code = code_so_far;
        right_code[64 - depth] = 1;
        compute_codes(node->right_, depth + 1, right_code);
      }
    }
  }
};

int main() { HuffmanTree ht("faust.txt"); }