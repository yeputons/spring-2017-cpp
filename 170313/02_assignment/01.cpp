#include <iostream>

struct A {
  int foo() {
    return 1;
  }
};

struct B : A {
  int foo() {
    return 2;
  }
};

int main() {
  B x;
  std::cout << x.foo() << "\n";  // 2
  delete x;
  return 0;
}
