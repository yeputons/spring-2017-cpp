#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <list>
#include "../../01_stl/02_helper.h"

template<typename T>
bool binary_search(T begin, T end, ?? value) {
  while (begin + 1 != end) {
    T mid = (begin + end) / 2;
    if (...) {
      begin = mid;
    } else {
      end = mid;
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
