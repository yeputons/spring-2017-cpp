#include <iostream>
#include <vector>

using namespace std;

vector<int> vi;
vector<bool> vb;

int main() {
  vi.resize(10);
  vb.resize(10);

  vi[0] = 0;
  int &x = vi[0];
  x = 1;
  cout << vi[0] << "\n";


  vb[0] = true;
  // Не компилируется, потому что vb[0] возвращает не `bool&`.
  // bool &y = vb[0];

  // Правильный тип вот такой длинный. Неудобно.
  // Ещё неудобнее, когда мы начинаем активно использовать `auto` из
  // C++11 (если не знаете - пока забейте).
  vector<bool>::reference y = vb[0];
  y = true;
  cout << vb[0] << "\n";
  // Подробнее, почему vector<bool> - плохой пример специализации:
  // http://alenacpp.blogspot.ru/2005/06/vector.html

  // Этот reference тоже можно перепривязывать.
  vector<bool>::reference z = y;
  z = false;
  cout << vb[0] << "\n";
}
