#include <exception>
#include <iostream>

// Подход, используемый в некоторых компаниях: возвращать флаг
// "была ли ошибка", а результат - в отдельную переменную.
bool divide(int a, int b, int &res) {
  if (b == 0) {
    return false;
  }
  res = a / b;
  return true;
}

int main() {
  int res;
  // Теперь всё работает, но дико неудобно пользоваться.
  std::cout << divide(5, 2, res) << "\n";
  std::cout << res << "\n";

  std::cout << divide(5, 0, res) << "\n";
  std::cout << res << "\n";

  std::cout << divide(2, -2, res) << "\n";
  std::cout << res << "\n";
  return 0;
}
