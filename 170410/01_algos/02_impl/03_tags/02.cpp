#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <list>

// Более эффективная реализация линейного "двоичного" поиска.
template<typename T>
bool my_binary_search(T begin, T end, typename std::iterator_traits<T>::value_type value) {
  for (; begin != end; begin++) {
    if (*begin == value) {
      return true;
    }
  }
  return false;
}

// Старый код.
#include <chrono>
template<typename T>
void fill(T& container) {
  for (int i = 0; i < 10000; i++) {
    container.push_back(i);
  }
}

template<typename T>
void check(const T& container) {
  using std::chrono::steady_clock;
  using std::chrono::duration_cast;
  using std::chrono::microseconds;

  steady_clock::time_point start = steady_clock::now();
  for (int i = 0; i < 10000; i++) {
    my_binary_search(container.begin(), container.end(), i);
  }
  std::cout << "Spent: " <<
    duration_cast<microseconds>(steady_clock::now() - start).count() << " us\n";
}

int main() {
  std::vector<int> v;
  fill(v);
  check(v);

  std::list<int> l;
  fill(l);
  check(l);
  return 0;
}
