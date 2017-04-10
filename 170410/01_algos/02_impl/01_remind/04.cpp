#include <vector>
#include <string>
#include <list>

// Функция print должна выводить на экран элементы переданного контейнера через запятую.
// Циклы использовать запрещено.


int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };
  std::list<double> d = { 0.5, 0.25, 0.9 };
  
  print(a, a + 3);
  print(a, a + sizeof(a) / sizeof(a[0]));
  print(std::begin(a), std::end(a));  // C++11

  print(b.begin(), b.end());
  print(std::begin(b), std::end(c));  // C++11, для единообразия.

  print(std::begin(c), std::end(c));  // C++11

  print(std::begin(d), std::end(d));  // C++11
  return 0;
}
