#ifndef MAGIC_H_
#define MAGIC_H_

class Something {
 public:
  bool operator==(const Something &) const {
    return false;
  }
};

#endif  // MAGIC_H_
