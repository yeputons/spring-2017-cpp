#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>

int multiply(int a, int b) {
  return a * b;
}

int main() {
  // Требуется написать код, считывающий n, затем n чисел (*_iterator), и выводящий:
  // 1. Сумму чисел (accumulate).
  // 2. Произведение чисел (accumulate).
  // 3. Числа в отсортированном порядке.
  // 4. Первый элемент, строго больший десяти (lower_bound, upper_bound).
  // 5. Количество элементов, лежащих в отрезке [5; 8] (lower_bound, upper_bound).
  // 6. Квадраты чисел в исходном порядке.

  int n;
  std::cin >> n;

  std::vector<int> v;

  {
    std::istream_iterator<int> in(std::cin);
    std::back_insert_iterator<std::vector<int>> out(v);
    std::copy(in, std::istream_iterator<int>(), out);
  }

  assert(v.size() == static_cast<std::size_t>(n));

  // Сумма чисел
  std::cout << std::accumulate(v.begin(), v.end(), 0) << "\n";

  // Произведение чисел, но умноженное на -1 (так как стартуем с -1, а не с 1).
  std::cout << std::accumulate(v.begin(), v.end(), -1, multiply) << "\n";


  // ЧИсла в отсортированном порядке.
  std::sort(v.begin(), v.end());
  {
    std::ostream_iterator<int> out(std::cout, "\n");
    std::copy(v.begin(), v.end(), out);
  }

  // Первый элемент, _строго_ больший 10.
  {
    std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), 10);
    // Как и другие STL'ные функция, upper_bound возвращает что-то в [begin; end],
    // то есть может вернуть end - можете считать, что в end лежит плюс бесконечность.
    if (it == v.end()) {
      std::cout << "Not found\n";
    } else {
      std::cout << *it << "\n";
    }
  }

  // upper_bound(R) - lower_bound(L) - это количество элементов со значениями [L; R].
  // lower_bound(R) - lower_bound(L) - это количество элементов со значениями [L; R).
  std::cout << std::upper_bound(v.begin(), v.end(), 8) - std::lower_bound(v.begin(), v.end(), 5) << "\n";
  // Напоминание: operator- для итераторов можно заменить на std::distance.
  std::cout << std::distance(
     std::lower_bound(v.begin(), v.end(), 5),
     std::upper_bound(v.begin(), v.end(), 8)) << "\n";

  std::list<int> foo = { 4, 5, 5, 6, 6, 7, 7, 8, 8, 9 };
  // Если у нас итераторы не random access, то надо использовать distance.
  // lower_bound/upper_bound всё ещё будут работать, но уже за линию, а не за логарифм.
  std::cout << std::distance(
     std::lower_bound(foo.begin(), foo.end(), 5),
     std::upper_bound(foo.begin(), foo.end(), 8)) << "\n";
  return 0;
}
