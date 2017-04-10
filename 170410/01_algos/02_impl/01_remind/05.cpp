#include <vector>
#include <string>
#include <list>
#include <iostream>

// Функция max должна возвращать максимальный элемент из контейнера.


int main() {
  int a[] = { 1, 2, 3 };
  std::vector<std::string> b = { "meow", "a", "woof" };
  const char* c[] = { "foo", "bar" };
  std::list<double> d = { 0.5, 0.25, 0.9 };
  
  std::cout << max(a, a + 3) << "\n"; 
  std::cout << max(a, a + sizeof(a) / sizeof(a[0])) << "\n"; 
  std::cout << max(std::begin(a), std::end(a)) << "\n";  // C++11

  std::cout << max(b.begin(), b.end()) << "\n";

  std::cout << max(std::begin(c), std::end(c)) << "\n";
  
  std::cout << max(d.begin(), d.end()) << "\n";
  return 0;
}
