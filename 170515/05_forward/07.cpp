#include "../democlass.h"
#include <iostream>
#include <utility>

void bar(const DemoClass &val) {
  std::cout << "bar cref: " << val << "\n";
}

void bar(DemoClass&& val) {
  std::cout << "bar rref: " << val << "\n";
}

template<typename T>
void foo(T&& val) {
  std::cout << "foo got: " << val << "\n";
  bar(std::forward<T>(val));
}

#include "main.h"
