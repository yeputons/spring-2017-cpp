#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> data = { 1, 2, 3 };
  std::ostream_iterator<int> out_it(std::cout, ", ");
  std::copy(data.begin(), data.end(), out_it);
  return 0;
}
