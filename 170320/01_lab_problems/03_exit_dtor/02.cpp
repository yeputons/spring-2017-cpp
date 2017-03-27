#include <iostream>
#include <cstdlib>

// Вопрос: какие деструкторы будут вызваны и в каком порядке?

class A {
 public:
  A(int val) : val_(val) {
    std::cout << "A(" << val_ << ")\n";
  }
  ~A() {
    std::cout << "~A(" << val_ << ")\n";
  }

 private:
  int val_;
};

A a1(1);
A *a2 = new A(2);

int main() {
  A a3(3);
  A *a4 = new A(4);
  delete a4;
  exit(0);  // Не вызывает деструкторы локальных переменных (a3). Лучше не использовать.
}
