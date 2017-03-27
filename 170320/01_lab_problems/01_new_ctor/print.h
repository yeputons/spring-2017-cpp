#ifndef PRINT_H_
#define PRINT_H_
// Макросы не должны начинаться с _ или содержать __
// http://stackoverflow.com/questions/228783

#include <iostream>

// using std::cout; // В заголовках нельзя даже "точный" using

template<typename T>
void print(T *arr, int len) {
  for (int i = 0; i < len; i++) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << arr[i];
  }
  std::cout << "\n";
}

#endif  // PRINT_H_