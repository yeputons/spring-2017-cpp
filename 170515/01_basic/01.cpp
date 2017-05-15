#include "../democlass.h"
#include <iostream>

int main() {
  std::cout << "----- DemoClass a(10) -----\n";
  DemoClass a(10);

  std::cout << "----- DemoClass b = a -----\n";
  DemoClass b = a;

  std::cout << "----- DemoClass c = DemoClass(20) -----\n";
  DemoClass c = DemoClass(20);

  std::cout << "----- DemoClass &d = a -----\n";
  DemoClass &d = a;

  std::cout << "----- DemoClass e = DemoClass(DemoClass(20)) -----\n";
  DemoClass e = DemoClass(DemoClass(20));

  std::cout << "----- d = c -----\n";
  d = c;

  std::cout << "----- b = DemoClass(30) -----\n";
  b = DemoClass(30);

  std::cout << "----- exit -----\n";
  return 0;
}
