#include "magic.h"
#include <assert.h>

int main() {
  Something a, b;
  // Вообще не всегда. На этой строчке программа молча завершится.
  a = b;
  assert(false);
  return 0;
}
