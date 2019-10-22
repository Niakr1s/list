#include <iostream>

#include "list.h"
#include "node.h"

int main() {
  List l;
  std::cout << "size: " << l.size() << std::endl;
  l.push(2);
  l.push(1);
  l.push(0);
  std::cout << "size: " << l.size() << std::endl;
  std::cout << l << std::endl;

  l.pop(l[1]);
  l.pop(l[1]);
  std::cout << "size: " << l.size() << std::endl;
  try {
    l.pop(l[1]);
  } catch (std::exception& e) {
    std::cout << "E: " << e.what() << std::endl;
  }
  std::cout << l << std::endl;
  l.pop(l[0]);
  std::cout << l << std::endl;

  return 0;
}
