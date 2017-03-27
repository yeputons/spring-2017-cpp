#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

using std::size_t;

template<typename T>
void print(T begin, T end) {
  for (T it = begin; it != end; it++) {
    if (it != begin) {
      std::cout << ' ';
    }
    std::cout << *it;
  }
  std::cout << "\n";
}
/*
// Почти то же самое, что:
for (int *i = &arr[0]; i != &arr[3]; i++) {
  std::cout << *i;
}
*/

int main() {
  std::string arr[] = { "bar", "baz", "foo" };
  std::vector<int> vec = { 1, 2, 3 };  // C++11
  std::list<char> lst = { 'a', 'b', 'c' };  // C++11
  std::set<char> st = { 'c', 'b', 'a' };  // C++11

  print(&arr[0], &arr[3]);
  print(arr, arr + 3);
  
  print(vec.begin(), vec.end());

  print(lst.begin(), lst.end());

  print(st.begin(), st.end());
  return 0;
}
