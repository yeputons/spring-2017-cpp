int main() {
  std::cout << "----- Foo a(10) -----\n";
  Foo a(10);

  std::cout << "----- Foo b = a -----\n";
  Foo b = a;

  std::cout << "----- Foo c = std::move(a) -----\n";
  Foo c = std::move(a);

  std::cout << "----- b = c -----\n";
  b = c;

  std::cout << "----- b = std::move(c) -----\n";
  b = std::move(c);

  std::cout << "----- exit -----\n";
  return 0;
}
