#include "../democlass.h"
#include <iostream>

struct Foo {
  DemoClass c;

  Foo(int key) : c(key) {}
};

#include "main.cpp"
