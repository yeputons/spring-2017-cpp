#include <cstdlib>
#include <iostream>
#include <memory.h>

int main() {
  unsigned int tmp[10];
  unsigned int x = 1;
  memset(tmp, x, sizeof tmp);
  std::cout << tmp[0] << "\n";
  // Упс, memset заполняет побайтово, несмотря на то, что тип второго
  // аргумента - `int`. Так исторически сложилось в функциях из C -
  // они часто принимают/возвращают `int` вместо `char`. Иногда это
  // оправдано (например, `getc()` должен иногда вернуть EOF, не являющийся
  // символов), а иногда - не очень.
  return 0;
}
