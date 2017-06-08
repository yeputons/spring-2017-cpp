#include <algorithm>
#include <iostream>

template<typename T>
void run_bubble(T &) {
}

template<typename T, typename U, typename... Args>
void run_bubble(T &a, U &b, Args&... args) {
  if (a > b) {
    std::swap(a, b);
    run_bubble(b, args...);
  }
}

void bubble_sort() {
}

template<typename T, typename... Args>
void bubble_sort(T &a, Args&... args) {
  bubble_sort(args...);
  run_bubble(a, args...);
}

int main() {
  int a = 4, b = 1, c = 3, d = 2;
  bubble_sort(a, b, c, d);
  return 0;
}
