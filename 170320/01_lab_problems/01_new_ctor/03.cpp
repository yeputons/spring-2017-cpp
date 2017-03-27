#include <ostream>
#include "print.h"

using std::ostream;

struct Integer {
  Integer() {}  // Конструктор ничего не меняет: он и раньше генерировался и вызывался компилятором.
  int value;
};
ostream& operator<<(ostream &os, const Integer &v) {
  return os << v.value;
}

int main() {
  Integer *arr = new Integer[10];
  print(arr, 10);  // Undefined behavior.
  delete[] arr;
  return 0;
}
