#include <exception>
#include <iostream>

int divide(int a, int b) {
  if (b == 0) {
    return -1;  // Магическое значение "ошибка".
  }
  return a / b;
}

int main() {
  std::cout << divide(5, 2) << "\n";
  std::cout << divide(5, 0) << "\n";
  std::cout << divide(2, -2) << "\n";  // Упс, магическое значение может возникнуть без ошибки.
  return 0;
}
