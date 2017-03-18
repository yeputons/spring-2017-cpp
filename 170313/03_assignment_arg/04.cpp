#include <iostream>
struct A {
  int x;

  A() : x(1) {}
  virtual ~A() {}  // Обязателен

  virtual int foo() {
    return x;
  }
};

struct B : A {
  int y;

  B() : y(2) {}

  /* virtual */ int foo() {  // Автоматически виртуальная
    return y;
  }
};

int main() {
  A *x = new B;
  std::cout << x->foo() << "\n";  // 2
  delete x;
  return 0;
}
