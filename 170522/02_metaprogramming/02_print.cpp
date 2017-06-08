#include <iostream>

//print_all [x] = print_one x; print_one "\n";
//print_all (x:xs) = print_one x; print_one ", "; print_all xs;

template<typename T>
//void writeln<T>(const T &x) { // Ошибка, не бывает частичных специализаций
void writeln(const T &x) { // Ошибка, не бывает частичных специализаций
  std::cout << x << "\n";
}

template<typename T, typename... OurArgTypes>
void writeln(const T &x, OurArgTypes... our_arg_values) {
  std::cout << x << " ";
  writeln(our_arg_values...);
}

int main() {
  int a = 10;
  std::string b = "foo";
  std::cout << a << ", " << b << "\n";
  writeln(a, b, 10.5);
  return 0;
}
