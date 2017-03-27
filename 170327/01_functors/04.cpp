#include <set>
#include "print.h"

using std::set;

struct my_greater {
  bool operator()(int a, int b) {
    return (a ^ 1) > (b ^ 1);
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
