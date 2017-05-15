#include "../democlass.h"
#include <iostream>

void foo_val(DemoClass x) {
  std::cout << "got " << x << "\n";
}

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

  std::cout << "----- foo_val(a) -----\n";
  foo_val(a);

  std::cout << "----- foo_val(DemoClass(20)) -----\n";
  foo_val(DemoClass(20));

  std::cout << "----- foo_val(std::move(a)) -----\n";
  foo_val(std::move(a));

  std::cout << "----- exit -----\n";
  return 0;
}
