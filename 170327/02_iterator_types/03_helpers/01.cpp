#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using std::cout;

template<typename T>
typename T::value_type middle(T begin, T end) {
  return begin[(end - begin) / 2];
}

int main() {
  std::vector<int> vec = { 1, 2, 3 };
  std::cout << middle(vec.begin(), vec.end()) << '\n';

//  std::list<int> lst = { 1, 2, 3 };
//  std::cout << middle(lst.begin(), lst.end()) << '\n';

//  int arr[] = { 1, 2, 3 };
//  std::cout << middle(arr, arr + 3) << '\n';
  return 0;
}

