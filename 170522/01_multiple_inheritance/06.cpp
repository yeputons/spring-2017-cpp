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

struct B : Base {
  int bx;
  virtual void foo() {
    std::cout << "B::foo\n";
  }
};

struct C : A, B {
  virtual void foo() {
    std::cout << "C::foo\n";
  }
};

int main() {
  C c;
  c.foo();
  c.A::foo();
  c.B::foo();

//  static_cast<Base&>(c).foo();
//  static_cast<A&>(c).foo();
//  static_cast<B&>(c).foo();
  return 0;
}
