#include "heap.hpp"

#include <cstdio>
#include <random>

struct Stud {
  Stud(int x = 0, float y = 5.0f) : matr_nr_{x}, note_{y} {}

  int matr_nr_;
  float note_;
};

struct CmpStudOperator {
  bool operator()(Stud const& lhs, Stud const& rhs) {
    return lhs.note_ < rhs.note_;
  }
};

CmpStudOperator cmp_stud;  // erzeuge 1 Objekt von der Klasse CmpStudOperator

int main() {
  Stud stud1(123123, 4.0f);
  Stud stud2(123124, 1.0f);

  PQ<Stud, CmpStudOperator> pq(882, cmp_stud);
  pq.push(stud1);
  pq.push(stud2);
  pq.push(Stud(124124, 2.0f));

  while (!pq.is_empty()) {
    Stud x = pq.extract_min();
    printf("(%i,%f)", x.matr_nr_, x.note_);
  }
  printf("\n");

  // int n = 1000;
  // PQ<int> pq(n);

  // std::random_device rd;

  // for (int i = 0; i < n; ++i) pq.push(rd() % 1000);

  // while (!pq.is_empty()) {
  //   int x = pq.extract_min();
  //   printf("%i,", x);
  // }
  // printf("\n");
}