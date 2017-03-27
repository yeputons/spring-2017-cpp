#include <set>
#include "print.h"

using std::set;

class my_greater {
 public:
  // Так как функтор - структура, то он может иметь состояние.
  my_greater(int change_bits) : change_bits_(change_bits) {}

  bool operator()(int a, int b) {
    return (a ^ change_bits_) < (b ^ change_bits_);
  }

 private:
  int change_bits_;
};

int main() {
  set<int, my_greater> x;  // Compilation error.
  for (int i = 0; i < 10; i++) {
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
