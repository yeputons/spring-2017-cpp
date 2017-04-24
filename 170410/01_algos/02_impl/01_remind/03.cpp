#include <vector>
#include <string>
#include <list>
#include <iostream>

// Функция print должна выводить на экран элементы переданного контейнера через запятую.
// Циклы использовать запрещено.

// Стандартная конвенция, чтобы разобраться с "нерешаемой" проблемой получения
// длины обрабатываемого отрезка - передать итераторы на [начало; конец).
template<typename T>
void print(T begin, T end) {
  bool first = true;
  while (begin != end) {
    if (!first) {
      std::cout << ", ";
    }
    first = false;
    std::cout << *begin;
    begin++;
  }
  std::cout << "\n";
}

int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };
  std::list<double> d = { 0.5, 0.25, 0.9 };

  print(a, a + 3);  // Для массива.
  print(a, a + sizeof(a) / sizeof(a[0]));  // Для статического массива. Работает и с `int*`, но неправильно.
  print(std::begin(a), std::end(a));  // C++11, для статического массива.

  print(b.begin(), b.end());  // Для контейнера.
  print(std::begin(b), std::end(b));  // C++11, для единообразия с массивами.

  print(std::begin(c), std::end(c));  // C++11

  print(std::begin(d), std::end(d));  // C++11
  return 0;
}
