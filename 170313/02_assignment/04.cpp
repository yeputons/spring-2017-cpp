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
  B *x = (B*)new A;  // Никогда так не делайте, наверняка это undefined behavior.
  std::cout << x->foo() << "\n";  // Тут компилятор снова посмотрел на тип указателя.
  delete x;
  return 0;
}
