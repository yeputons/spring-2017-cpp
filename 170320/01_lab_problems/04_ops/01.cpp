struct Integer {
  Integer(int init_value) : value(init_value) {}
  Integer operator+(Integer &other) {  // Упс?
    return Integer(value + other.value);
  }

  int value;
};

int main() {
  Integer a(1), b(2);
  Integer res = a + b;
  return 0;
}
