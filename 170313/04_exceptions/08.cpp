#include <iostream>
#include <vector>

using std::size_t;
using std::vector;
using std::ostream;
using std::cout;

class SizeMismatch {
};

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

vector<int> operator+(vector<int> a, int b) {
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

vector<int> a = { 1, 2, 3 };
vector<int> b = { 4, 5, 6 };

// Ошибка может происходить сколь угодно глубоко в стеке вызовов,
// в случае исключения все функции будут прерваны до ближайшего
// catch, который сможет обработать исключение.
vector<int> bar() {
  return a + (a + 0) * b;
}
vector<int> foo() {
  return bar();
}

int main() {
  std::cout << a << "\n" << b << "\n";
  std::cout << (a + a + b) << "\n";
  std::cout << (a + a * b) << "\n";
  try {
    std::cout << foo() << "\n";
  } catch (const SizeMismatch &error) {
    std::cout << "Oops, size mismatch\n";
  }
}
