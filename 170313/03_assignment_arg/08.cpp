#include <iostream>
struct A {
  int x;

  A() : x(1) {}
  virtual ~A() {}

  virtual int foo() {
    return x;
  }
};

struct B : A {
  int y;

  B() : y(2) {}

  virtual int foo() {
    return y;
  }
};

// А теперь - по значению.
void bar(A x) {
  // Всё срезалось до `A`, поле `y` потеряно.
  std::cout << x.foo() << "\n";  // 1
}

int main() {
  A *x = new B;
  bar(*x);
  delete x;
  return 0;
}
