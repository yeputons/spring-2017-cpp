#include <iostream>
#include <string>
#include <vector>

using std::size_t;

template<typename T>
void print(const T &arr, size_t length) {
  for (size_t i = 0; i < length; i++) {
    if (i != 0) {
      std::cout << ' ';
    }
    std::cout << arr[i];
  }
  std::cout << "\n";
}

int main() {
  std::string arr[] = { "bar", "baz", "foo" };
  std::vector<int> vec = { 1, 2, 3 };  // C++11
  print(arr, 3);
  print(vec, 3);
  return 0;
}
