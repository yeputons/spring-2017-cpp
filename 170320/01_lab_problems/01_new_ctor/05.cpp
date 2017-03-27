#include <ostream>
#include "print.h"

using std::ostream;

struct Integer {
  Integer() : value(239017) {  // Можно задать явное значение при инициализации.
     //value = 239017; // Так лучше не стоит, потому что для нетривиальных объектов
                       // будет лишний вызов конструктора и operator= вместо вызова
                       // конструктора напрямую.
  }
  int value;
};
ostream& operator<<(ostream &os, const Integer &v) {
  return os << v.value;
}

int main() {
  Integer *arr = new Integer[10];
  print(arr, 10);  // Выводит 239017.
  delete[] arr;
  return 0;
}
