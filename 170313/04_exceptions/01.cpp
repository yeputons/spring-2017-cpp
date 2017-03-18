#include <exception>
#include <iostream>

int divide(int a, int b) {
  return a / b;
}

int main() {
  std::cout << divide(5, 2) << "\n";
  std::cout << divide(5, 0) << "\n";  // упс, как сообщить об ошибке?
  return 0;
}
