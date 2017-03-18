#include <exception>
#include <iostream>

class DivideByZeroException {};

int divide(int a, int b) {
  if (b == 0) {
    throw DivideByZeroException();
    // В целом можно кидать что угодно, хоть ноль.
    // Но не надо: кидайте только специально предназначенные для этого классы.
    throw 0
  }
  return a / b;
}

int main() {
  std::cout << divide(5, 2) << "\n";
  try {
    std::cout << divide(5, 0) << "\n";
  } catch (const DivideByZeroException &e) {
    // Правильно принимать исключение по ссылке, чтобы не срезалось.
    // Rule of thumb: в catch всегда идёт константная ссылка.
    std::cout << "oops";
  }
  std::cout << divide(2, -2) << "\n";
  return 0;
}
