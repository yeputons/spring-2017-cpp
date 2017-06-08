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

struct C1 : C {
  virtual void foo() {
    std::cout << "C1::foo\n";
  }
  int ax;
  int cx;
};

struct D : B, C1 {
  int dx;
};

int main() {
  D d;
  // d.foo();

  d.B::foo();
  d.A::foo();
  d.Base::foo();
  d.C1::foo();
  d.C::foo();

  (static_cast<B&>(d)).foo();
  (static_cast<A&>(d)).foo();
  (static_cast<Base&>(d)).foo();
  (static_cast<C1&>(d)).foo();
  (static_cast<C&>(d)).foo();
  return 0;
}
