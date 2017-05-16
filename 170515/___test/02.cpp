#include <stdio.h>
#include <vector>
#include "person.h"

struct foo {
  FILE *f;
  std::vector<Person> loaded;

  foo() : f(nullptr) {}

  foo(const foo &) = delete;
  foo& operator=(const foo &) = delete;

  foo(foo&& other) : f(other.f), loaded(std::move(other.loaded)) {
    other.f = nullptr;
  }
  foo& operator=(foo &&other) {
    if (f) {
      fclose(f);
    }
    f = other.f;
    other.f = nullptr;
    loaded = std::move(other.loaded);
//    std::swap(f, other.f);
//    std::swap(loaded, other.loaded);
//    loaded.swap(other.loaded);
  }
/*
  foo& operator=(foo other) {
    std::swap(f, other.f);
    std::swap(loaded, other.loaded);
  }
*/
  ~foo() {
    if (f) {
      fclose(f);
    }
  }
};

int main() {
  return 0;
}
