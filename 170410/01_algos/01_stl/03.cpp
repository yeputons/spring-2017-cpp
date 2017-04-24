#include <set>

int main() {
  std::set<int> a;
  lower_bound(a.begin(), a.end(), 10);  // O(n), потому что итераторы не random acces.
  a.lower_bound(10);  // O(log n), так как set<> может эксплуатировать свою внутреннюю структуру.
  return 0;
}
