#include <set>
#include "print.h"

using std::set;

struct my_greater {
  bool operator()(int a, int b) {
    return (a % 2) > (b % 2);
  }
  // !(a < b)   a >= b
  // !(b < a)   b >= a
  // (a >= b) && (b >= a)    a == b
};

int main() {
  set<int, my_greater> x;
  for (int i = 9; i >= 0; i--) {
    // Аналогично предыдущему, тут просто первыми
    // будут добавлены элементы 9 и 8, а не 0 и 1.
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
