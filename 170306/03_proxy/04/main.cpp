#include <iostream>
#include "magic.h"

int main() {
  int x = 2, y = 3;
  Something a(x, y);
  std::cout << x << " " << y << "\n";
  Something b(a);  // Копировать тоже в целом можно.
  // Something b = a;
  b = 5;
  std::cout << x << " " << y << "\n";
  return 0;
}
