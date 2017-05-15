#include "../democlass.h"
#include <iostream>

struct Foo {
  DemoClass c;

  Foo(int key) : c(key) {}
  Foo(const Foo &other) : c(other.c) {}
  Foo(Foo &&other) : c(other.c) {}

  Foo& operator=(const Foo &other) {
    c = other.c;
    return *this;
  }

  Foo& operator=(Foo &&other) {
    c = other.c;
    return *this;
  }
};

#include "main.cpp"
