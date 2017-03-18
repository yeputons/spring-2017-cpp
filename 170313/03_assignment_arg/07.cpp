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

// Теперь не указатель, а ссылка.
void bar(A &x) {
  std::cout << x.foo() << "\n";  // 2
}

int main() {
  A *x = new B;
  bar(*x);
  delete x;
  return 0;
}
