#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "02_helper.h"

int main() {
  std::vector<int> v;
  fill(v);   // Добавить в вектор 10000 элементов.
  check(v);  // Измерим, сколько времени займут 10000 двоичных поисков.

  std::list<int> l;
  fill(l);   // Аналогично для списка.
  check(l);  // Должно занять сильно больше времени - binary_search уже за линию.
  return 0;
}
