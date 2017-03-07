#include <cstddef>
#include <assert.h>
#include <stdio.h>

// Очень простой вектор для `int`, который нельзя копировать (для простоты).
class my_vector {
 public:
  my_vector(std::size_t length) : data_(new int[length]) {
  }
  ~my_vector() {
    delete[] data_;
  }

  // Ошибка: есть const qualifier, но возвращается неконстантная ссылка.
  int& operator[](std::size_t index) const {
    return data_[index];
  }

 private:
  my_vector(const my_vector&);
  my_vector& operator=(const my_vector&);

  int* data_;
};

void foo(const my_vector &v) {
  // Упс, смогли изменить константный объект.
  v[0] = 5;
}

int main() {
  my_vector v(5);
  v[0] = 10;

  foo(v);  // Передача как бы по константной ссылке.

  // Объект, тем не менее, поменялся.
  assert(v[0] == 10);
}

// Проблема в том, что const qualifier запрещает менять *поля объекта*.
// Но если поле - указатель, то константным становится лишь сам указатель, а не
// те данные, на которые он указывает. Другими словами, до const qualifier:
//     int *data_;
// После:
//     int * const data_;
// А вовсе не:
//    const int *data_;
