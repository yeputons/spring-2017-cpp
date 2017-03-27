#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::size_t;

template<typename T>
bool binary_search(T begin, T end, const T& value) {
  // ...
}

int main() {
  std::string arr[] = { "bar", "baz", "foo" };
  std::vector<int> vec = { 1, 2, 3 };  // C++11
  std::list<char> lst = { 'a', 'b', 'c' };  // C++11

  assert(binary_search(arr, arr + 3, "foo"));
  assert(binary_search(vec.begin(), vec.end(), 1));
  // assert(binary_search(lst.begin(), lst.end(), 'c'));
  return 0;
}
