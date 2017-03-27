#include <vector>

using std::vector;

struct pair_vector {
  // INVARIANT: a.size() == b.size()

  void push_back(int a_val, int b_val) {
    try {
      a.push_back(a_val);
      b.push_back(b_val);
    } catch (...) {
      // Теперь только базовая гарантия: если что-то пошло не так - очищаем pair_vector.
      // Он в корректном состоянии, но состояние сильно поменялось по сравнению с тем,
      // что было до вызовов push_back().
      a.clear();
      b.clear();
      throw;
    }
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
