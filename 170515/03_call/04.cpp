#include "../democlass.h"
#include <iostream>

void foo_val(DemoClass x) {
  std::cout << "got " << x << "\n";
}

int main() {
  {
    std::cout << "----- DemoClass a(10) -----\n";
    DemoClass a(10);

    std::cout << "----- foo_val(a) -----\n";
    foo_val(std::move(a));

    std::cout << "----- exit block -----\n";
  }
  std::cout << "----- exit -----\n";
  return 0;
}
