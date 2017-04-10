#include <vector>
#include <string>
#include <list>

// Функция print должна выводить на экран элементы переданного контейнера через запятую.


int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };
  std::list<double> d = { 0.5, 0.25, 0.9 };
  
  print(a);
  print(b);
  print(c);
  print(d);
  return 0;
}
