#include <map>
#include <string>
#include <sstream>

using std::map;
using std::string;

struct Matrix {
};

int main() {
  // Полезный трюк, чтобы не парсить руками названия регистров.
  // Храним все матрицы в map: по названию регистра хранится матрица.
  map<string, Matrix> regs;
  for (int i = 0; i < 10; i++) {
    // Способ форматирования строк в C++03.
    std::stringstream name;  // Поток, в который можно выводить, как в cout.
    name << '$' << i;
    regs[name.str()] = Matrix();  // А потом методом str() получить то, что было выведено.
    // regs["$" + std::to_string(i)] = Matrix();  // В C++11 появилась функция to_string(int).
  }

  regs["$0"] += regs["$1"];  // Дальше можно писать операции вот так.
  return 0;
}
