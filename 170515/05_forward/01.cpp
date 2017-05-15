#include "../democlass.h"
#include <iostream>

template<typename T>
void foo(T val) {
  std::cout << "foo_got: " << val << "\n";
}

#include "main.h"
