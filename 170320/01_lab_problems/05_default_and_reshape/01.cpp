#include <vector>
#include <iostream>

using std::vector;
using std::cout;

// Просто класс матрицы, которую можно вывести на экран.
// Подвоха в определении класса почти нет (см. подвох в main).

class Matrix {
 public:
  Matrix(int rows = 0, int cols = 0)
    : data_(rows, vector<int>(cols))
  {
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
  Matrix a;  // То же самое, что вызвать конструктор (). В нашем случае - конструктор, а параметры взять по умолчанию.
  Matrix b(1, 4);  // Вызываем конструктор с явными параметрами.
  Matrix c = 5;  // C++ видит int, пробует неявно привести его к Matrix, вызвав конструктор Matrix(int). Получается - у нас второй параметр остаётся по умолчанию. В C++11 лечится словом explicit.
  Matrix d(5);  // То же самое, словом explicit уже не лечится. Забыли параметр - огребли. Такое в случае матриц обычно никогда не нужно.
  cout << "A:\n" << a;
  cout << "B:\n" << b;
  cout << "C:\n" << c;
  return 0;
}
