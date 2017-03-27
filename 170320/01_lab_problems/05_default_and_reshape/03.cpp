#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Matrix {
 public:
  Matrix() {}
  Matrix(int rows, int cols)
    : data_(rows, vector<int>(cols))
  {
  }

  void reshape(int rows, int cols) {
    // Была проблема: resize использует второй параметр только для заполнения
    // свежедобавленных строк. Старые строки не меняются.
    // Надо либо сначала удалить все строки, а потом создать новые...
    data_.clear();
    data_.resize(rows, vector<int>(cols));
    // ... либо использовать operator= ...
    data_ = vector<vector<int>>(rows, vector<int>(cols));
    // ... либо метод assign - то же самое, но короче:
    data_.assign(rows, vector<int>(cols));
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
