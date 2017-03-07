#include <assert.h>
#include "magic.h"

int main() {
  Something a;
  // Не всегда операторы следуют "очевидной" семантике.
  assert(a == a);
  return 0;
}
