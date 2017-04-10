#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <list>
#include "../../01_stl/02_helper.h"

template<typename T>
bool binary_search(T begin, T end, ?? value) {
  for (; begin != end; begin++) {
    if (*begin == value) {
      return true;
    }
  }
  return false;
}

// Старый код.

int main() {
  std::vector<int> v;
  fill(v);
  check(v);

  std::list<int> l;
  fill(l);
  check(l);
  return 0;
}
