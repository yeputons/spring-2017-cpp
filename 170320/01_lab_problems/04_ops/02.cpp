struct Integer {
  Integer(int init_value) : value(init_value) {}
  Integer operator+(Integer &other) {
    return Integer(value + other.value);
  }

  int value;
};

int main() {
  Integer a(1), b(2), c(3);
  Integer res = a + b + c;
  return 0;
}
