#include <ostream>
#include "print.h"

using std::ostream;

struct Integer {
  int value;  // Default initialization для int - опять отсутствие инициализации.
};
ostream& operator<<(ostream &os, const Integer &v) {
  return os << v.value;
}

int main() {
  Integer *arr = new Integer[10];  // Default initialization.
  print(arr, 10);  // Undefined behavior.
  delete[] arr;
  return 0;
}
