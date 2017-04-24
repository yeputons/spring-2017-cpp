#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <type_traits>

// Функция max должна возвращать максимальный элемент из контейнера.

// Напоминание про iterator_traits.
template<typename T>
typename std::iterator_traits<T>::value_type my_max(T begin, T end) {
  T it = begin;
  for (; begin != end; begin++) {
    if (*begin > *it) {
      it = begin;
    }
  }
  return *it;
}

int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };
  std::list<double> d = { 0.5, 0.25, 0.9 };

  std::cout << my_max(a, a + 3) << "\n";
  std::cout << my_max(a, a + sizeof(a) / sizeof(a[0])) << "\n";
  std::cout << my_max(std::begin(a), std::end(a)) << "\n";  // C++11

  std::cout << my_max(b.begin(), b.end()) << "\n";

  std::cout << my_max(std::begin(c), std::end(c)) << "\n";

  std::cout << my_max(d.begin(), d.end()) << "\n";
  return 0;
}
