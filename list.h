#ifndef LIST_H
#define LIST_H

#include <iostream>

class Node;

class List {
 public:
  List() : first_(nullptr) {}

  void push(int n);
  bool pop();
  bool pop(Node* ptr);
  int size();

  friend std::ostream& operator<<(std::ostream& out, const List& ths);
  Node* operator[](int pos);

 private:
  Node* first_;
};

std::ostream& operator<<(std::ostream& out, const List& ths);

#endif  // LIST_H
