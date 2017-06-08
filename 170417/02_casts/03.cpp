1.
void send(char *, int len);

const char *str = "foo";
send(const_cast<char*>(str), );

2.
int operator[](int x) const {
  return data[x];
}

int& operator[](int x) {
  return data[x];
}

//
int operator[](int x) const {
  return const_cast<T&>(*this)[x];
}

int& operator[](int x) {
  return data[x];
}

3.

int a = 5;
const int &b = a;
const_cast<int&>(b) = 4;
// Легально ^^^

const int a = 5;
const_cast<int&>(a) = 4;
// undefined behavior.
