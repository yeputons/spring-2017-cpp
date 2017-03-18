#include <iostream>
struct A {
  int x;

  A() : x(1) {}

  int foo() {
    return x;
  }
};

struct B : A {
  int y;

  B() : y(2) {}

  int foo() {
    return y;
  }
};

int main() {
  A *x = new A;
  std::cout << x->foo() << "\n";  // 1
  delete x;
  return 0;
}
