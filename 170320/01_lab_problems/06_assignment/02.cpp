class Integer {
  Integer() : data(new int()) {}
  Integer(const Integer &other) : data(new int(*other.data)) {}
  ~Integer() {
    delete data;
  }

  Integer& operator=(const Integer &other) {
    // Кто-то писал так: явно вызываем деструктор, потом заново инициализируем поля.
    this->~Integer();
    data = new int(*other.data); // Undefined behavior: объект уничтожен, к полям обращаться нельзя вообще.
    return *this;
  }

  int *data;
};

int main() {
}
