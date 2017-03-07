#ifndef MAGIC_H_
#define MAGIC_H_

#include <stdlib.h>

class Something {
 public:
  Something& operator=(const Something &) {
    exit(0);
  }
};

#endif  // MAGIC_H_
