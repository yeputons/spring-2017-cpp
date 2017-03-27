#include <set>
#include "print.h"

using std::set;

int main() {
  set<int> x;
  for (int i = 9; i >= 0; i++) {
    x.insert(i);
  }
  // Выводит элементы в отсортированном порядке,
  // так как set<> внутри себя их хранит в
  // отсортированном порядке.
  print(x.begin(), x.end());
  return 0;
}
