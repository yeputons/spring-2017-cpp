#include <set>
#include "print.h"

using std::set;

class my_greater {
 public:
  my_greater(int change_bits) : change_bits_(change_bits) {}

  bool operator()(int a, int b) {
    return (a ^ change_bits_) < (b ^ change_bits_);
  }

 private:
  int change_bits_;
};

int main() {
  // Так как нет конструктора по умолчанию, то set<>
  // не может сам создать функтор. Надо ему явно передать
  // объект, который он будет использовать для сравнения
  // элементов внутри себя.
  //
  // Функторы активно используются в STL: set, lower_bound,
  // sort, partition, remove_if, unique и прочие структуры и
  // алгоритмы. Некий аналог в Python - лямбда-функции.
  set<int, my_greater> x(my_greater(1));
  for (int i = 0; i < 10; i++) {
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
