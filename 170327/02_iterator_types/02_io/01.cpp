#include <iostream>
#include <iterator>

int main() {
  std::ostream_iterator<int> out_it(std::cout, ", ");
  *out_it = 1;
  out_it++;
  *out_it = 2;
  out_it++;
  *out_it = 3;
  out_it++;
  return 0;
}
