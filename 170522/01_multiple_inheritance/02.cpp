#include <iostream>

struct Base {
  virtual void foo() {}
};

struct A : Base {
  int ax;
  virtual void foo() {}
};

struct B : A {
  int bx;
};

struct C {
  int cx;
};

struct D : B, C {
  int dx;
};

int main() {
  D d;
  std::cout << &d << "\n";
//  std::cout << &d.ax << "\n";
//  std::cout << &d.bx << "\n";
//  std::cout << &d.cx << "\n";
//  std::cout << &d.dx << "\n";'
  std::cout << static_cast<A*>(&d) << "\n";
  std::cout << static_cast<B*>(&d) << "\n";
  std::cout << static_cast<C*>(&d) << "\n";
  std::cout << static_cast<D*>(&d) << "\n";
  return 0;
}
