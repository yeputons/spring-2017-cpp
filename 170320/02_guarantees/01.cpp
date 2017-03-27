#include <cstdio>
#include <memory>

template<typename T>
struct my_vector {
  // Тут нет кучи методов (деструктор), это просто демонстрация кода.

  my_vector(const my_vector &other)
    : arr((T*)(new char[other.len * sizeof(T)]))
  {
    // Если вылетит исключение в процессе копирования, то
    // вектор останется частично инициализированным:
    // 0 1 2 x x
    // Так как исключение вылетело в конструкторе, то
    // объект будет считаться несозданным и деструктор вызываться не
    // будет. Получаем утечку ресурсов в уже сконструированных объектах.
    for (int i = 0; i < len; i++) {
      new (arr + i) T(other.arr[i]);
    }
  }

  void operator=(const my_vector &other) {
    delete[] (char*)arr;
    arr = new char[other.len * sizeof(T)];  // Если не хватило памяти, то arr != NULL в деструкторе, но уже уничтожено - double free, упс.
    // Аналогичная конструктора проблема тут.
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
