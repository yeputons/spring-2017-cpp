#include <iostream>
#include <iterator>

class nat_iterator {
 public:
  nat_iterator(int value) : value_(value) {
  }

  int operator*() const {
    return value_;
  }

  nat_iterator& operator++() {
    value_++;
    return *this;
  }

 private:
  int value_;
};

int main() {
  nat_iterator it(5);
  std::cout << *it << ' ';
  std::cout << *(++it) << ' ';
  // std::cout << *(it++) << ' ';
  std::cout << *it << '\n';
  return 0;
}
