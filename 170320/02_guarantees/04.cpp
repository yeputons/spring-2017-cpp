#include <cstdio>
#include <memory>

template<typename T>
struct my_vector {
  my_vector(const my_vector &other)
    : arr((T*)(new char[other.len * sizeof(T)]))
  {
    // 0 1 2 x x
    int i = 0;
    try {
      while (i < len) {
        new (arr + i) T(other.arr[i]);
        i++;
      }
    } catch (...) {
      while (i > 0) {
        i--;
        arr[i].~T();
      }
      delete[] (char*)arr;
      throw;
    }
  }

  my_vector& operator=(const my_vector &other) {
    // Гораздо лучше делать copy-swap: всю работу за нас сделает
    // конструктор копирования и собственноручно написанный метод swap().
    // Вызвали конструктор копирования, поменялись местами с other_copy,
    my_vector other_copy(other);
    swap(other_copy);
    // Старые элементы лежат в other_copy, который будет уничтожен
    // (и уничтожит старые элементы) при выходе из функции.
    return *this;
  }
  // или вот так:
  my_vector& operator=(my_vector other) {  // Конструктор копирования вызывается при передаче по значению.
    swap(other);
    return *this;
  }

  void swap(const my_vector &other) {
    // Важно писать именно std::swap(), иначе иногда компилятор попробует
    // вызвать метод swap(), в котором мы сейчас находимся (не прямо здесь, но может).
    std::swap(arr, other.arr);
    std::swap(len, other.len);
  }
  
  T* arr;
  int len;
};

int main() {
  return 0;
}
