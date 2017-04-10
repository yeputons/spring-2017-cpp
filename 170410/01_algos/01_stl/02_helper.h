#ifndef H_01_STL_02_HELPER_H_
#define H_01_STL_02_HELPER_H_

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
    std::binary_search(container.begin(), container.end(), i);
  }
  std::cout << "Spent: " <<
    duration_cast<microseconds>(steady_clock::now() - start).count() << " us\n";
}

#endif  // H_01_STL_02_HELPER_H_
