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
  A *x = new B;
  std::cout << x->foo() << "\n";  // 1, компилятор смотрит только на тип указателя.
  delete x;
  return 0;
}
