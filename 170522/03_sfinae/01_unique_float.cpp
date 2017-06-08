#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

template<typename T>
typename std::enable_if<!std::is_floating_point<T>::value, void>::type unique(std::vector<T> &v) {
  std::size_t added = 0;
  for (const T &cur : v) {
    if (added == 0 || v[added - 1] != cur) {
      v[added++] = cur;
    }
    // v[0..added - 1] - правильный ответ для v[..cur]
  }
  v.resize(added);
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type unique(std::vector<T> &v) {
  std::size_t added = 0;
  for (const T &cur : v) {
    if (added == 0 || fabs(v[added - 1] - cur) > 1e-2) {
      v[added++] = cur;
    }
    // v[0..added - 1] - правильный ответ для v[..cur]
  }
  v.resize(added);
}

/*
  std::size_t i = 0;
  while (i + 1 < v.size()) {
    if (v[i] == v[i + 1]) {
      v.erase(v.begin() + i);
    } else {
      i++;
    }
  }
}*/

int main() {
  std::vector<int> a = { 1, 2, 2, 2, 1, 3, 1, 1 };
  unique<int>(a);
  for (auto x : a)
    std::cout << x << " ";
  std::cout << "\n";

  std::vector<double> b = { 1 - 1e-5, 1 };
//  b.erase(std::unique(b.begin(), b.end(),
//    [](double a, double b) { return fabs(a - b) < 1e9; }
//  ), b.end());
  unique(b);
  for (auto x : b)
    std::cout << x << " ";
  std::cout << "\n";

  std::vector<float> b1 = { 1 - 1e-5, 1 };
  unique(b1);
  for (auto x : b1)
    std::cout << x << " ";
  std::cout << "\n";

/*  char *x = "foo";
  char y[] = "foo";
  std::vector<char*> c = { "foo", "foo", "bar", "foo", "foo", x, y };
//  b.erase(std::unique(b.begin(), b.end(),
//    [](double a, double b) { return fabs(a - b) < 1e9; }
//  ), b.end());
  unique(c);
  for (auto x : c)
    std::cout << x << " ";
  std::cout << "\n";*/
  return 0;
}
