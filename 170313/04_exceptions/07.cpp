#include <iostream>
#include <vector>

using std::size_t;
using std::vector;
using std::ostream;
using std::cout;

class SizeMismatch {
};

// Почленное сложение векторов.
vector<int> operator+(const vector<int> &a, const vector<int> &b) {
  if (a.size() != b.size()) {
    throw SizeMismatch();
  }
  vector<int> result(a.size());
  for (size_t i = 0; i < a.size(); i++) {
    result[i] = a[i] + b[i];
  }
  return result;
}

// Добавление элемента к вектору.
vector<int> operator+(vector<int> a, int b) {
  // Обратите внимание, что вектор тут передаётся по значению - это сделано
  // намеренно, потому что нам в любом случае потребуется его скопировать.
  // А так избегаем создания локальной переменной-копии.
  a.push_back(b);
  return a;
}

vector<int> operator*(const vector<int> &a, const vector<int> &b) {
  if (a.size() != b.size()) {
    throw SizeMismatch();
  }
  vector<int> result(a.size());
  for (size_t i = 0; i < a.size(); i++) {
    result[i] = a[i] * b[i];
  }
  return result;
}

ostream& operator<<(ostream& os, const vector<int> &a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i) {
      os << " ";
    }
    os << a[i];
  }
  return os;
}

int main() {
  vector<int> a = { 1, 2, 3 };
  vector<int> b = { 4, 5, 6 };
  std::cout << a << "\n" << b << "\n";
  // Если ошибок не возникает - пишем удобный синтаксис с операторами.
  // Заметьте, что с оператором не прокатил бы трюк "возвращать значение
  // в третьем аргументе".
  std::cout << (a + a + b) << "\n";
  std::cout << (a + a * b) << "\n";
  try {
    // Тут ошибка возникнет глубоко внутри, но мы её всё равно поймаем.
    std::cout << (a + (a + 0) * b) << "\n";
  } catch (const SizeMismatch &error) {
    std::cout << "Oops, size mismatch\n";
  }
}
