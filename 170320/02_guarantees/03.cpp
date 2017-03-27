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
    // Для начала мы забыли классический случай.
    if (&other == *this) {
      return *this;
    }
    // Теперь добъёмся базовой гарантии.
    // TODO: на занятии тут забыли вызвать конструкторы старых элементов.
    delete[] (char*)arr;
    arr = nullptr;  // Если уничтожили - сразу переведём вектор в корректное состояние,
                    // чтобы не огрести в случае "new кинул исключение". Это будет не
                    // строгая гарантия, лишь базовая - если new выкинул исключение,
                    // то старые элементы будут убиты.
    len = 0;

    arr = (T*)(new char[other.len * sizeof(T)]);

    for (int i = 0; i < other.len; i++) {
      try {
        new (arr+i) T(other.arr[i]);
      } catch (...) {
        // Аналогично конструктору: если что-то произошло, надо уничтожить
        // уже созданные объекты.
        for (int j = i - 1; j >= 0; j--) {
          arr[j].~T();
        }
        delete[] (char*)arr;
        arr = nullptr;  // Но в отличие от конструктора, надо оставить объект в корректном состоянии.
        throw;
      }
    }
    len = other.len;
    return *this;
  }
  
  T* arr;
  int len;
};

int main() {
  return 0;
}
