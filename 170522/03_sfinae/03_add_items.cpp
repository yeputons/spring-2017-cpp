#include <vector>
#include <set>

template<typename T>
auto add_ten(T &container) -> decltype(container.insert(10), void()) {
  container.insert(10);
}

template<typename T>
auto add_ten(T &container) -> decltype(container.push_back(10), void()) {
  container.push_back(10);
}

int main() {
  std::vector<int> a;
  std::set<int> b;
  add_ten(a);
  add_ten(b);
  return 0;
}
