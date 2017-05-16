#include <iostream>

template<typename T>
bool XXX(const T& a, const T& b) {
   return a == b;
}

template<typename T, typename... Args>
bool XXX(const T& a, const T& b, Args... args) {
  return a == b && XXX(args...);
}

int main() {
  std::cout << XXX(1, 1, 2, 2, 3, 3) << "\n"; // true
  std::cout << XXX(1, 2, 3, 4, 5, 6) << "\n"; // false
  return 0;
}