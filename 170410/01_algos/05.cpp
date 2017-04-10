#include <vector>
#include <string>
#include <iostream>

// Функция unique должна удалять одинаковые подряд идущие элементы из контейнера.
// Принимает два итератора.


int main() {
  std::vector<int> a = { 1, 1, 2, 1, 3, 3, 3, 4, 5, 5 };

  unique(a.begin(), a.end());  // ???

  print(a);
  return 0;
}
