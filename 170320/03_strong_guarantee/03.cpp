#include <vector>

using std::vector;

struct pair_vector {
  // INVARIANT: a.size() == b.size()

  void push_back(int a_val, int b_val) {
    a.push_back(a_val);
    try {
      b.push_back(b_val);
    } catch (...) {
      // А вот теперь есть базовая гарантия. Если что-то упало - вернули как было.
      // Это даже строгая гарантия: если возникло исключение, то значение pair_vector
      // не изменилось.
      a.pop_back();
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
