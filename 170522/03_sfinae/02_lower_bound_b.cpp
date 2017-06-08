#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <type_traits>

// https://stackoverflow.com/questions/257288

template<typename Container, typename Arg>
struct has_lower_bound {
private:
  template<typename T>
  static auto foo(int) -> decltype(
    std::declval<T>().lower_bound(std::declval<Arg>())  // Пробуем вызвать метод
    ,
    std::true_type()
  );

  template<typename>
  static std::false_type foo(...);  // Приоритет при выборе перегрузки у ... минимален

public:
  using type = decltype(foo<Container>(0));
//  typedef decltype(foo<Container>(0)) type;  // То же самое
  static const bool value = type::value;
};

template<typename T, typename V>
typename std::enable_if<!has_lower_bound<T, V>::value, typename T::const_iterator>::type
my_lower_bound(const T &container, const V &value) {
  std::cout << "Calling global lower_bound\n";
  return std::lower_bound(container.begin(), container.end(), value);
}

template<typename T, typename V>
typename std::enable_if<has_lower_bound<T, V>::value, typename T::const_iterator>::type
my_lower_bound(const T &container, const V &value) {
  std::cout << "Calling lower_bound method\n";
  return container.lower_bound(value);
}

int main() {
  std::set<int> a = { 1, 2, 3, 5, 6, 7 };
  std::vector<int> b = { 1, 2, 3, 5, 6, 7 };

  std::cout << "set: " << has_lower_bound<std::set<int>, int>::value << "\n";
  std::cout << *my_lower_bound(a, 4) << "\n";

  std::cout << "vector: " << has_lower_bound<std::vector<int>, int>::value << "\n";
  std::cout << *my_lower_bound(b, 4) << "\n";
  return 0;

}
