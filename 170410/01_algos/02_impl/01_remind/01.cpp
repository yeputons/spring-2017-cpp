#include <vector>
#include <string>

// Функция print должна выводить на экран элементы переданного массива через запятую.


int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };
  
  print(a);
  print(b);
  print(c);
  return 0;
}
