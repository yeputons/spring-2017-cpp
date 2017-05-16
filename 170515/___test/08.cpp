int main() {
  std::unique_ptr<Person> foo() { … }
  void bar(const std::unique_ptr<Person> &p) { … }
  void baz(std::unique_ptr<Person> p) { … }

  auto x = foo();
  auto &y = x;
  bar(y);
  Person *ptr = x.get();
  ptr->foo_bar();
  baz(std::move(x));
}