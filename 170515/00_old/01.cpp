#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

void foo(vector<int> b) {
  b.clear();
//  sort(b.begin(), b.end());
  // do something.
}

vector<int> operator+(vector<int> a, int b) {
  for (std::size_t i = 0; i < a.size(); i++) {
    a[i] += b;
  }
  return a;
}

int main() {
  clock_t start = clock();  // C++03
  vector<int> data(1000000);
  for (int i = 0; i < 1000; i++) {
    foo(data + 1);
  }
  std::cout << "Spent: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << " sec\n";
  return 0;
}
