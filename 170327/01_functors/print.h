#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>

template<typename T>
void print(T begin, T end) {
  for (T it = begin; it != end; it++) {
    if (it != begin) {
      std::cout << ' ';
    }
    std::cout << *it;
  }
  std::cout << "\n";
}

#endif  // PRINT_H_