int main() {
  std::cout << "----- DemoClass a(10) -----\n";
  DemoClass a(10);

  std::cout << "----- foo(a) -----\n";
  foo(a);

  std::cout << "----- foo(DemoClass(20)) -----\n";
  foo(DemoClass(20));

  std::cout << "----- foo(std::move(a)) -----\n";
  foo(std::move(a));

  std::cout << "----- exit -----\n";
  return 0;
}
