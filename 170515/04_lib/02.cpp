#include "../democlass.h"
#include <iostream>

struct Foo {
  DemoClass c;

  Foo(int key) : c(key) {}
  ~Foo() {}
};

#include "main.cpp"
