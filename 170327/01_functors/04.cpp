#include <set>
#include "print.h"

using std::set;

struct my_greater {
  // Можно писать более страшные выражения.
  // Главное - чтобы присутствовал линейный порядок на элементах.
  bool operator()(int a, int b) {
    return (a ^ 1) > (b ^ 1);
  }
/*
  stored: 0 1 2 3
  compar: 1 0 3 2

  operator(0, 1) = false
    (0 ^ 1) > (1 ^ 1)
        1   >   0
           false
  operator(0, 2)
     0 ^ 1 >  2  ^ 1
       1   >    3
          false
  operator(2, 0)
     2 ^ 1 >  0  ^ 1
       3   >    1
          true
*/
};

int main() {
  set<int, my_greater> x;
  for (int i = 0; i < 10; i++) {
    x.insert(i);
  }
  print(x.begin(), x.end());
  return 0;
}
