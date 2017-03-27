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
    } catch (...) {  // Если что-то случилось, надо уничтожить уже созданные объекты.
      while (i > 0) {
        i--;
        arr[i].~T();  // Предполагается, что деструкторы исключения не кидают. Если кинул - abort() - см. 05.cpp
      }
      delete[] (char*)arr;  // Аналогично: память освободить мы всегда можем.
      throw;  // Об ошибке стоит сообщить вызвавшему конструктор, иначе он обнаружит себя с несконструированным вектором.
    }
  }

  void operator=(const my_vector &other) {
    // Всё ещё есть проблемы с operator=.
    delete[] (char*)arr;
    arr = new char[other.len * sizeof(T)];
    for (int i = 0; i < len; i++) {
      new (arr+i) T(other.arr[i]);
    }
  }
  
  T* arr;
  int len;
};

int main() {
  return 0;
}
