#include <algorithm>
#include <iostream>
#include <math.h>

int main() {
  std::vector<int> v = {50, -10, 20, -30};
  std::sort(v.begin(), v.end(), [](int lhs, int rhs) {
    return abs(lhs) < abs(rhs);
  });
  for (int x : v)
    std::cout << x << "\n";
  return 0;
}
