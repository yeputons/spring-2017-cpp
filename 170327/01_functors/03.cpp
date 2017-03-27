#include <set>
#include "print.h"

using std::set;

// Можно написать свой greater.
struct my_greater {
  // Притворяемся функцией, чтобы можно было писать так:
  //     my_greater something;
  //     bool x = something(1, 2);
  // Структура с оператором () называется "функтор".
  bool operator()(int a, int b) {
    return a > b;
  }
};

int main() {
  set<int, my_greater> x;
  for (int i = 0; i < 10; i++) {
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
