#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <list>
#include "../../01_stl/02_helper.h"

template<typename T>
bool binary_search(T begin, T end, ?? value, std::random_access_iterator_tag) {
  binary_search(begin, end, iterator_traits<T>::iterator_category());
}

template<typename T>
bool binary_search(T begin, T end, ?? value, std::input_iterator_tag) {
  binary_search(begin, end, iterator_traits<T>::iterator_category());
}

template<typename T>
bool binary_search(T begin, T end, ?? value) {
  binary_search(begin, end, value, iterator_traits<T>::iterator_category());
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
