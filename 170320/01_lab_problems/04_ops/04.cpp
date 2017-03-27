struct Integer {
  Integer(int init_value) : value(init_value) {}
  Integer operator+(Integer &other) {
    return Integer(value + other.value);
  }

  int value;
};

int main() {
  Integer a(1), b(2), c(3);
  Integer res = a + (b + c);  // Но если написать вот так, то не получится вызвать operator+.
                              // Его аргумент - временное значение, которое по правилам нельзя
                              // привязать к неконстантной ссылке.
  return 0;
}
