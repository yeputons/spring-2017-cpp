#include <iostream>

#pragma pack(push, 1)
struct Base {
  int id;
  virtual void foo() {
    std::cout << "Base::foo(" << &id << ")\n";
  }
};

struct A : virtual Base {
  int ax;
  virtual void foo() {
    std::cout << "A::foo(" << &id << ")\n";
  }
};

struct B : virtual Base {
  int bx;
  virtual void foo() {
    std::cout << "B::foo(" << &id << ")\n";
  }
};

struct C : A, B {
  virtual void foo() {
    std::cout << "C::foo(" << &id << ")\n";
  }
};

int main() {
  C c;
  std::cout << "&c=" << &c << "\n";
  std::cout << static_cast<A*>(&c) << "\n";
  std::cout << static_cast<B*>(&c) << "\n";
  std::cout << static_cast<Base*>(&c) << "\n";
  c.foo();
  c.A::foo();
  c.B::foo();
  c.Base::foo();
  std::cout << sizeof(Base) << "\n";
  std::cout << sizeof(A) << "\n";
  std::cout << sizeof(B) << "\n";
  std::cout << sizeof(C) << "\n";

//  static_cast<Base&>(c).foo();
//  static_cast<A&>(c).foo();
//  static_cast<B&>(c).foo();
  return 0;
}
