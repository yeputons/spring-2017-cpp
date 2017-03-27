struct A {
  ~A() {
    throw 0;  // Если исключение покинуло деструктор - abort().
  }
};

int main() {
  try {
    try {
      {
        A a;
      }
    } catch (...) {
    }
  } catch (...) {
  }
  return 0;
}
