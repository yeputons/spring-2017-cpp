#include "../democlass.h"
#include <iostream>

DemoClass foo(int key) {
  std::cout << "  --- DemoClass result(0) ---\n";
  DemoClass result(0);
  if (key == 10) {
    std::cout << "  --- result = DemoClass(30) ---\n";
    result = DemoClass(30);
  }
  return result;
}

int main() {
  std::cout << "----- DemoClass a(10) -----\n";
  DemoClass a(10);

  std::cout << "----- a = foo(20) -----\n";
  a = foo(20);

  std::cout << "----- exit -----\n";
  return 0;
}
