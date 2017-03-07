#ifndef MAGIC_H_
#define MAGIC_H_

#include <stdlib.h>

class Something {
 public:
  Something(int &a, int &b) : a_(a), b_(b) {
  }
  Something& operator=(int x) {
    a_ = x;
    b_ = x;
    return *this;
  }

 private:
  int &a_;
  int &b_;
};

#endif  // MAGIC_H_
