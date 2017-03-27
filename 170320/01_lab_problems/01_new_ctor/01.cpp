#include "print.h"

int main() {
  // Default initialization: для простых типов это значит "не проинициализировано"
  int *arr = new int[10];  // Default initialization.
  print(arr, 10);  // Выводит что угодно: undefined behavior.
  delete[] arr;
  return 0;
}
