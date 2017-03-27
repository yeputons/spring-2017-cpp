#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::istream_iterator<int> in_it(std::cin);
  std::istream_iterator<int> end_of_stream;

  std::vector<int> data;
  std::back_insert_iterator<std::vector<int>> data_inserter(data);
  std::copy(in_it, end_of_stream, data_inserter);

  std::ostream_iterator<int> out_it(std::cout, ", ");
  std::copy(data.begin(), data.end(), out_it);
  
  return 0;
}
