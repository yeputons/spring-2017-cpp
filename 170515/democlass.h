#ifndef DEMOCLASS_H_
#define DEMOCLASS_H_

#include <iostream>
#include <cstddef>

class DemoClass {
public:
  explicit DemoClass(int key) : key_(key) {
    std::cout << "Constructed " << *this << "\n";
  }

  DemoClass(const DemoClass &other) : key_(other.key_) {
    std::cout << "Copy-constructed " << *this << " from " << other << "\n";
  }

  DemoClass(DemoClass &&other) : key_(std::move(other.key_)) {
    std::cout << "Move-constructed " << *this << " from " << other << "\n";
  }
  
  DemoClass& operator=(const DemoClass &other) {
    key_ = other.key_;
    std::cout << "Copy-assigned " << *this << " from " << other << "\n";
    return *this;
  }
  
  DemoClass& operator=(DemoClass &&other) {
    key_ = std::move(other.key_);
    std::cout << "Move-assigned " << *this << " from " << other << "\n";
    return *this;
  }
  
  ~DemoClass() {
    std::cout << "Destructed " << *this << "\n";
  }

  friend std::ostream& operator<<(std::ostream &os, const DemoClass &o) {
    int addr_hash = (reinterpret_cast<std::size_t>(&o) * 239017) % 100;
    os << "(" << o.key_ << "; " << addr_hash << ")";
    return os;
  }

private:
  int key_;
};

#endif  // DEMOCLASS_H_
