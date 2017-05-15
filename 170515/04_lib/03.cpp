#include "../democlass.h"
#include <iostream>

struct Foo {
  DemoClass c;

  Foo(int key) : c(key) {}
  Foo(const Foo &other) : c(other.c) {}
};

#include "main.cpp"
