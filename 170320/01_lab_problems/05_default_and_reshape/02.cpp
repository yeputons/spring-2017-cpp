#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Matrix {
 public:
  // Чтобы интерфейс было сложно использовать неправильно, лучше сделать два отдельных
  // конструктора - один по умолчанию (без параметров), другой - с двумя параметрами
  // (оба обязательные). Тогда нельзя вызвать Matrix(int) ни явно, ни неявно.
  Matrix() {}
  Matrix(int rows, int cols)
    : data_(rows, vector<int>(cols))
  {
  }

  // Что должно происходить: матрица меняет свой размер на новый,
  // что происходит с данными - неважно. В реализации есть ошибка.
  // Какая? Запустите - увидите.
  void reshape(int rows, int cols) {
    data_.resize(rows, vector<int>(cols));
  }

  friend std::ostream& operator<<(std::ostream &os, const Matrix &m) {
    for (std::size_t row = 0; row < m.data_.size(); row++) {
      for (std::size_t col = 0; col < m.data_[row].size(); col++) {
        if (col) {
          os << ' ';
        }
        os << m.data_[row][col];
      }
      os << '\n';
    }
    return os;
  }

 private:
  vector<vector<int>> data_;
};

int main() {
  Matrix a;
  Matrix b(1, 4);
  // Matrix c = 5;
  cout << "A:\n" << a;
  cout << "B:\n" << b;

  b.reshape(4, 1);
  cout << "A:\n" << a;
  cout << "B:\n" << b;
  return 0;
}
