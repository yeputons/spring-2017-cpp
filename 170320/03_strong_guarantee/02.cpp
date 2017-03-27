#include <vector>

using std::vector;

struct pair_vector {
  // ИНВАРИАНТ: a.size() == b.size()

  void push_back(int a_val, int b_val) {
    a.push_back(a_val);
    // Теперь нет даже базовой гарантии: если b.push_back() упадёт,
    // то нарушится инвариант объекта, он будет в некорректном состоянии.
    // Мораль: надо думать, не всегда две операции с базовой гарантией
    // образуют операцию с базовой гарантией.
    b.push_back(b_val);
  }

  vector<int> a;
  vector<int> b;
};

int main() {
  pair_vector foo;
  try {
    foo.push_back(1, 2);
  } catch (...) {
  }
  return 0;
}
