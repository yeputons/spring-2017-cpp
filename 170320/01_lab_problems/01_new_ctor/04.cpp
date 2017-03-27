#include <ostream>
#include "print.h"

using std::ostream;

struct Integer {
  Integer() : value() {}  // А вот добавление скобочек делает value initialization.
  int value;  // Value initialization для int - ноль.
};
ostream& operator<<(ostream &os, const Integer &v) {
  return os << v.value;
}

int main() {
  Integer *arr = new Integer[10];
  print(arr, 10);  // Выводит нули.
  delete[] arr;
  return 0;
}
