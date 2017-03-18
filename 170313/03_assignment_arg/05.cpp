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
  B *x = (B*)new A;  // Никогда так не делайте.
  std::cout << x->foo() << "\n";  // undefined behavior
  delete x;
  return 0;
}
