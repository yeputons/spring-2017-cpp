#include <vector>
#include <string>
#include <list>
#include <iostream>

// Функция print должна выводить на экран элементы переданного контейнера через запятую.
template<typename T>
void print(const T& container) {
  // Решаемая проблема:
  // 1. operator[] мы уже не можем использовать, надо итераторы.
  // Нерешаемые проблема:
  // 1. Какая длина контейнера (если мы разрешаем массивы)?
  //    Сможем получить, если у нас статический массив (потому что размер зашит в тип),
  //    но не для динамического. Для него из типа размер никак не получить.
  // 2. А какой тип у iterator? Надо использовать что-то вроде iterator_traits
  //    для контейнеров, но такого нет (впрочем, теоретически можно было бы сделать).
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
  std::list<double> d = { 0.5, 0.25, 0.9 };

  // print(a); // Упс, у массива нет .size()
  print(b);
  // print(c); // Упс, у массива нет .size()
  // print(d); // Упс, у списка нет operator[]
  return 0;
}
