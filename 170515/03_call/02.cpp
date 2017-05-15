#include "../democlass.h"
#include <iostream>

void foo_ref(DemoClass &x) {
  std::cout << "got " << x << "\n";
}

void foo_cref(const DemoClass &x) {
  std::cout << "got " << x << "\n";
}

void foo_rref(DemoClass &&x) {
  std::cout << "got " << x << "\n";
}

int main() {
  std::cout << "----- DemoClass a(10) -----\n";
  DemoClass a(10);

  std::cout << "----- foo_ref(std::move(a)) fails -----\n";
  // foo_ref(std::move(a));

  std::cout << "----- foo_cref(std::move(a)) -----\n";
  foo_cref(std::move(a));

  std::cout << "----- foo_rref(std::move(a)) -----\n";
  foo_rref(std::move(a));

  std::cout << "----- foo_rref(DemoClass(20)) -----\n";
  foo_rref(DemoClass(20));

  std::cout << "----- exit -----\n";
  return 0;
}
