class Integer {
  // Вопрос: чего не хватает в классе?
  Integer() : data(new int()) {}
  ~Integer() {
    delete data;
  }

  int *data;
};

int main() {
}
