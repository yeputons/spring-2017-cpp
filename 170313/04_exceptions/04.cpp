#include <exception>
#include <iostream>

class DivideByZeroException {};

int divide(int a, int b) {
  if (b == 0) {
    throw DivideByZeroException();
  }
  vector<int> aaa(10);  // Может теоретически выкинуть ошибку bad_alloc, если не хватит памяти.
  return a / b;
}

int main() {
  std::cout << divide(5, 2) << "\n";
  try {
    std::cout << divide(5, 0) << "\n";
  } catch (...) {  // Ловит вообще все исключения, хотя мы тут намеревались ловить только DivideByZeroException.
    std::cout << "oops";
  }
  std::cout << divide(2, -2) << "\n";
  return 0;
}
