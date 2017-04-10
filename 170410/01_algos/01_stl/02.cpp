#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "02_helper.h"

int main() {
  std::vector<int> v;
  fill(v);
  check(v);

  std::list<int> l;
  fill(l);
  check(l);
  return 0;
}
