#include <vector>

using std::vector;

struct pair_vector {
  // INVARIANT: a.size() == b.size()

  void push_back(int a_val, int b_val) {
    try {
      a.push_back(a_val);
      b.push_back(b_val);
    } catch (...) {
      // Какая-то чушь и undefined behavior: если исключение выкинул a.push_back(),
      // то мы тоже вызовем a.pop_back().
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
