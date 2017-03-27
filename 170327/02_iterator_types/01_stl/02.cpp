#include <iostream>
#include <string>
#include <vector>
#include <list>

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

int main() {
  std::string arr[] = { "bar", "baz", "foo" };
  std::vector<int> vec = { 1, 2, 3 };  // C++11
  std::list<char> lst = { 'a', 'b', 'c' };  // C++11

  print(&arr[0], &arr[3]);
  print(arr, arr + 3);
  
  print(vec.begin(), vec.end());

  print(lst.begin(), lst.end());
  return 0;
}
