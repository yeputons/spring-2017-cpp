#include <algorithm>
#include <iostream>
#include <set>

/*
template<typename T, typename V>
typename T::const_iterator lower_bound(const T &container, const V &value) {
  return std::lower_bound(container.begin(), container.end(), value);
}*/

template<typename T, typename V>
auto lower_bound(const T &container, const V &value) -> decltype(container.lower_bound(value)) {
  return container.lower_bound(value);
}

int main() {
  std::set<int> a = { 1, 2, 3, 5, 6, 7 };
  std::cout << *lower_bound(a, 4) << "\n";
  return 0;
}
