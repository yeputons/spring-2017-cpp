#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> vec = { 1, 2, 3, 2 };  // C++11
  std::cout << count(vec.begin(), vec.end(), 2) << '\n';
  return 0;
}
