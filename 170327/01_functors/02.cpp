#include <functional>
#include <set>
#include "print.h"

using std::set;

int main() {
  // std::greater<int> говорит, что раньше
  // должен быть больший элемент (а не меньший).
  // Т.е. set теперь хранит элементы по убыванию.
  set<int, std::greater<int> > x;
  for (int i = 0; i < 10; i++) {
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
