#include <memory>

class Integer {
  Integer() : data(new int()) {}
  Integer(const Integer &other) : data(new int(*other.data)) {}
  ~Integer() {
    delete data;
  }

  Integer& operator=(const Integer &other) {
    this->~Integer();
    new (this) Integer();  // Теоретически можно попробовать placement new.
                           // Но я не уверен, что тут нет undefined behavior.
                           // К тому же если вылетит исключение, то объект полностью
                           // сломается, не будет даже базовой гарантии.
                           // Правильно делать copy-swap.
    *data = *other.data;
    return *this;
  }

  int *data;
};

int main() {
}
