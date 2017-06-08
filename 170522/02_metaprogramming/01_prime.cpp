#include <iostream>

// isPrime n x = (n % x == 0) ? false : (isPrime n (x - 1))
// isPrime n 1 = true

template<int n, int x>
struct is_prime_ {
  static const bool value = (n % x == 0) ? false : is_prime_<n, x - 1>::value;
};

template<int n>
struct is_prime_<n, 1> {
  static const bool value = true;
};

template<int n>
struct is_prime {
  static const bool value = is_prime_<n, n - 1>::value;
};

template<>
struct is_prime<1> {
};

int main() {
//  std::cout << 1 << " " << is_prime<1>::value << "\n";
  std::cout << 2 << " " << is_prime<2>::value << "\n";
  std::cout << 3 << " " << is_prime<3>::value << "\n";
  std::cout << 4 << " " << is_prime<4>::value << "\n";
  std::cout << 5 << " " << is_prime<5>::value << "\n";
  std::cout << 6 << " " << is_prime<6>::value << "\n";
  std::cout << 7 << " " << is_prime<7>::value << "\n";
  std::cout << 8 << " " << is_prime<8>::value << "\n";
  std::cout << 9 << " " << is_prime<9>::value << "\n";
  std::cout << 10 << " " << is_prime<10>::value << "\n";
  std::cout << 11 << " " << is_prime<11>::value << "\n";
  return 0;
}
