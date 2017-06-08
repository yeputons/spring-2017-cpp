int main() {
  // Тут не нужен - и так произойдёт.
  int a = static_cast<int>(1e9), b = static_cast<int>(1e9);
  long long x = static_cast<long long>(a) * b;
  return 0;
}


class Foo {
};

class Bar : Foo {
};

Foo* x;
Bar* y;

x = y;  // Можно.
y = static_cast<Bar*>(x);  // Можно, но аккуратно.

static_cast<Bar>(*x);

// данные <FOO> данные
//        ^
