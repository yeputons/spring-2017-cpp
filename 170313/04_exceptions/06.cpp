#include <exception>
#include <iostream>

class DivideByZeroException {};

// Можно выстраивать иерархии исключений. Например, не всем
// может быть интересно, какая именно ошибка ввода-вывода произошла.
// А кому-то может быть интересно.
class IOException {
  // something
};
class FileNotFound : IOException {
  // something
};

int main() {
  try {
    // something
  } catch (const FileNotFound &e) {
    // Сначала обрабатываем наиболее "нижний" класс, так как
    // catch "пробуются" сверху вниз. Если сначала обработаем
    // IOException - то никогда не обработаем FileNotFound.
    std::cout << "oops";
  } catch (const IOException &e) {
    std::cout << "oops";
  } catch (const DivideByZeroException &e) {
    std::cout << "oops";
  }
  return 0;
}
