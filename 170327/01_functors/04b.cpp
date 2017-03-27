#include <set>
#include "print.h"

using std::set;

struct my_greater {
  // Тут тоже есть линейный порядок. Просто некоторые
  // элементы, разные с точки зрения int, будут одинаковыми
  // с точки зрения компаратора.
  bool operator()(int a, int b) {
    return (a % 2) > (b % 2);
  }
  // !(a < b)   ==>           a >= b
  // !(b < a)   ==>           b >= a
  // (a >= b) && (b >= a) ==> a == b
};

int main() {
  set<int, my_greater> x;
  for (int i = 0; i < 10; i++) {
    // При i=2 и дальше set<> обнаружит, что такой
    // элемент уже есть (с точки зрения компаратора)
    // и не будет добавлять ничего нового.
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
