#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
  friend class List;

 public:
  Node(int n) : n_(n) {}
  int n() { return n_; }
  int size();

  friend std::ostream& operator<<(std::ostream& out, const Node& ths);
  Node* operator[](int pos);

 private:
  int n_;
  Node *prev_, *next_;
};

std::ostream& operator<<(std::ostream& out, const Node& ths);

#endif  // NODE_H
