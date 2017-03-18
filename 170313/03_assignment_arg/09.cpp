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

  B() : y(2) {
    // Конструктор A() вызывается перед B(), так что мы перезапишем x.
    x = 10;
  }

  virtual int foo() {
    return y;
  }
};

void bar(A x) {
  // Так как при срезе был вызван конструктор копирования `A(const A& other);`,
  // то `B`, очевидно, туда передался, но у него поинтересовались только полем
  // `x`, которое успешно переписали в параметр функции. А там было 10.
  std::cout << x.foo() << "\n";  // 10
}

int main() {
  A *x = new B;
  bar(*x);
  delete x;
  return 0;
}
