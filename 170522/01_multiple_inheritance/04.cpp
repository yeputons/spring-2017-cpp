#include <iostream>

struct Base {
  virtual void foo() {
    std::cout << "Base::foo\n";
  }
};

struct A : Base {
  int ax;
  virtual void foo() {
    std::cout << "A::foo\n";
  }
};

struct B : A {
  int bx;
};

struct C {
  virtual void foo() {
    std::cout << "C::foo\n";
  }
  int ax;
  int cx;
};

struct D : B, C {
  int dx;
};

int main() {
  D d;
  // d.foo();

  d.B::foo();
  d.C::foo();
  d.Base::foo();

  (static_cast<C&>(d)).foo();
  (static_cast<B&>(d)).foo();
  (static_cast<Base&>(d)).foo();
  return 0;
}
