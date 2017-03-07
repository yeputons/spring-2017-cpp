#include <assert.h>
#include <vector>

class Something {
 private:
  class Proxy {
   public:
    Proxy(Something *s) : s_(s) {}
    operator int() {  // Неявное приведение к int.
      return s_->value;
    }
    void operator=(int new_value) {
      s_->value = new_value;
    }
    Something *s_;
  };

 public:
  int value;

  // Сложный объект возвращаем по значению.
  Proxy getProxy() {  // как бы `operator[]`
    // Созданный `Proxy` должен знать, у кого ему менять значение.
    // Можно было бы просто дать ссылку на `value_`.
    return Proxy(this);
  }
};

int main() {
  Something x;
  x.value = 10;
  assert(x.value == 10);

  // Работает на чтение: `x.getProxy()` вернул `Proxy`, а у него есть
  // оператор неявного приведения к `int`.
  assert(x.getProxy() == 10);

  // Работает на запись: `x.getProxy()` вернул `Proxy`, а у него есть
  // оператор `=`, который меняет `x.value`.
  x.getProxy() = 15;
  assert(x.value == 15);

  // Важное наблюдение: `x.getProxy()` понятия не имеет, с какой стороны
  // от `=` или `==` оно стоит, поэтому должно возвращать объект, который
  // "мимикрирует" под ссылку на `int`: есть и `operator=`, и в выражениях
  // вместо `int` может участвовать (из-за неявного приведения).

  std::vector<bool> v(1);
  // Следующие две строчки абсолютно идентичны. Это пример того, как
  // разворачивается "синтаксический сахар" под названием "операторы".
  v[0] = true;
  (v.operator[](0)).operator=(true);
}
