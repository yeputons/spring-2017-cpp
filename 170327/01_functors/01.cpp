#include <set>
#include "print.h"

using std::set;

int main() {
  set<int> x;
  for (int i = 0; i < 10; i++) {
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
