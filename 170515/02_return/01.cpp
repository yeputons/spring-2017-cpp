#include "../democlass.h"
#include <iostream>

DemoClass foo(int key) {
  std::cout << "  --- return DemoClass(key) ---\n";
  return DemoClass(key);
}

int main() {
  std::cout << "----- DemoClass a(foo(10)) -----\n";
  DemoClass a(foo(10));

  std::cout << "----- DemoClass b = foo(20) -----\n";
  DemoClass b = foo(20);

  std::cout << "----- a = foo(30) -----\n";
  a = foo(20);

  std::cout << "----- exit -----\n";
  return 0;
}
