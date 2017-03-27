#include "print.h"

// Копия 01.cpp.

int main() {
  int *arr = new int[10]();  // Добавили скобочки после new - стало value initialization.
  print(arr, 10);  // Выводит нули.
  delete[] arr;
  return 0;
}
