#include <vector>

using std::vector;

struct pair_vector {
  void push_back(int a_val, int b_val) {
    // Есть базовая гарантия, так как каждый push_back предоставляет базовую гарантию.
    // Но есть подвох.
    a.push_back(a_val);
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
