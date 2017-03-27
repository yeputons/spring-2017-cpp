#include <iostream>
#include <iterator>
#include <algorithm>

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

  nat_iterator operator++(int) {
    nat_iterator old = *this;
    ++*this;
    return old;
  }

  bool operator==(const nat_iterator &other) const {
    return value_ == other.value_;
  }

  bool operator!=(const nat_iterator &other) const {
    return value_ != other.value_;
  }

 private:
  int value_;
};

int main() {
  nat_iterator start(5);
  nat_iterator stop(10);
  std::cout << std::count(start, stop, 6) << '\n';
  return 0;
}
