#include <vector>
#include <string>
#include <iostream>

// Функция print должна выводить на экран элементы переданного массива/вектора через запятую.
template<typename T>
void print(const T& container) {
  for (std::size_t i = 0; i < container.size(); i++) {
    if (i) {
      std::cout << ", ";
    }
    std::cout << container[i];
  }
  std::cout << "\n";
}

int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };

  // print(a); // Упс, у массива нет .size()
  print(b);
  // print(c); // Упс, у массива нет .size()
  return 0;
}
