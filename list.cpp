#include "list.h"

#include <stdexcept>

#include "node.h"

std::ostream& operator<<(std::ostream& out, const List& ths) {
  if (ths.first_ != nullptr) {
    out << *ths.first_;
  } else {
    out << "Empty.";
  }
  return out;
}

void List::push(int n) {
  Node* to_push = new Node(n);
  if (first_ == nullptr) {
    first_ = to_push;
    return;
  }
  first_->prev_ = to_push;
  to_push->next_ = first_;
  first_ = to_push;
  return;
}

bool List::pop() {
  if (first_ == nullptr) {
    return false;
  }
  auto tmp = first_->next_;
  if (tmp != nullptr) {
    tmp->prev_ = nullptr;
  }
  delete (first_);
  first_ = tmp;
  return true;
}

bool List::pop(Node* ptr) {
  if (ptr == nullptr)
    return false;
  if (ptr == first_) {
    return pop();
  }
  if (ptr->next_ != nullptr) {
    ptr->next_->prev_ = ptr->prev_;
  }
  if (ptr->prev_ != nullptr) {
    ptr->prev_->next_ = ptr->next_;
  }
  delete (ptr);
  return true;
}

int List::size() {
  if (first_ == nullptr) {
    return 0;
  }
  return first_->size();
}

Node* List::operator[](int pos) {
  if (first_ == nullptr || pos < 0) {
    throw std::out_of_range("List: bad subscr");
  }
  auto ret = (*first_)[pos];
  if (ret == nullptr)
    throw std::out_of_range("List: bad subscr");
  return ret;
}
