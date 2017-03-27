#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using std::cout;

template<typename T>
typename std::iterator_traits<T>::value_type middle(T begin, T end) {
  std::advance(begin, std::distance(begin, end) / 2);
  return *begin;
}

int main() {
  std::vector<int> vec = { 1, 2, 3 };
  std::cout << middle(vec.begin(), vec.end()) << '\n';

  std::list<int> lst = { 1, 2, 3 };
  std::cout << middle(lst.begin(), lst.end()) << '\n';

  int arr[] = { 1, 2, 3 };
  std::cout << middle(arr, arr + 3) << '\n';
  return 0;
}

