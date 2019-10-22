#include "node.h"

#include <stdexcept>

std::ostream& operator<<(std::ostream& out, const Node& ths) {
  out << ths.n_;
  if (ths.next_ == nullptr) {
    out << ".";
  } else {
    out << ", " << *ths.next_;
  }
  return out;
}

int Node::size() {
  if (next_ == nullptr)
    return 1;
  return 1 + next_->size();
}

Node* Node::operator[](int pos) {
  if (pos == 0)
    return this;
  if (next_ == nullptr)
    throw std::out_of_range("Node: bad subscr");
  return (*next_)[pos - 1];
}
