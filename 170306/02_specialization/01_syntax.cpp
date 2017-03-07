#include <iostream>

// Просто учим синтаксис.
template<typename T> // Обычный шаблон.
class Callback {
public:
  void call(T a) {
    std::cout << "call(" << a << ")\n";
  }
};

// Говорим, что конкретно для Callback<void> у нас другой класс.
// Важно: шаблонные классы после подстановки типов вообще никак друг
// с другом не связаны. Нет никаких ограничений.
template<>
class Callback<void> {
public:
  // Например, можно определить вообще другой набор методов с другим названиями.
  void call_with_void() {
    std::cout << "call()\n";
  }
};

// Более реалистичный пример.
template<typename T>
struct hash {
  std::size_t operator()(const T&) const;
};

struct Something {
  int hash() const { return 0; }
};

template<>
struct hash<Something> {
  std::size_t operator()(const Something &s) const {
    return s.hash();
  }
};

/*
hash<Something> h;
int hash = h(Something());
*/

int main() {
  Callback<int> v;
  Callback<void> v2;
  v.call(1);
  v2.call_with_void();
}
