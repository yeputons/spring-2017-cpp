#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  // Можно передать ifstream.
  std::istream_iterator<int> in_it(std::cin);
  std::istream_iterator<int> end_of_stream;

  std::ostream_iterator<int> out_it(std::cout, "\n");
  std::copy(in_it, end_of_stream, out_it);
  return 0;
}
