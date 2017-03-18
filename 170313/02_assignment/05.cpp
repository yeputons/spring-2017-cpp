#include <iostream>

struct A {
  virtual ~A() {}  // Виртуальный деструктор нужен ВСЕГДА, если есть виртуальные функции.
  virtual int foo() {
    return 1;
  }
};

struct B : A {
  // Эта функция автоматически становится виртуальной.
  /* virtual */ int foo() {
    return 2;
  }
};

int main() {
  A *x = new B;
  std::cout << x->foo() << "\n";  // 2
  delete x;
  return 0;
}
