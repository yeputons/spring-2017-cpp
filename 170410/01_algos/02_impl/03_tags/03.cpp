#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <list>
#include "../../01_stl/02_helper.h"

// Реализация за логафрим (что такое tag - см. ниже).
template<typename T>
bool my_binary_search(T begin, T end, typename std::iterator_traits<T>::value_type value, std::random_access_iterator_tag) {
  // Инвариант как раньше.
  while (begin != end) {
    T mid = begin + (end - begin) / 2;
    // 'advance' is '+='
    // 'distance' is '-'
//    std::advance(mid, std::distance(begin, end) / 2);
    if (*begin == value) {
      return true;
    }
    if (*begin < value) {
      begin = mid + 1;
    } else {
      end = mid;
    }
  }
  return false;
}

// Реализация за линию (что такое tag - см. ниже).
template<typename T>
bool my_binary_search(T begin, T end, typename std::iterator_traits<T>::value_type value, std::input_iterator_tag) {
  for (; begin != end; begin++) {
    if (*begin == value) {
      return true;
    }
  }
  return false;
}

// Функция-фасад.
template<typename T>
bool my_binary_search(T begin, T end, typename std::iterator_traits<T>::value_type value) {
  // std::iterator_traits<T>::iterator_category - это какой-то тип. Например,
  // input_iterator_tag или random_access_iterator_tag. Дальше вступает в действие
  // перегрузка: выбирается my_binary_search с четвёртым параметром, лучше всего подходящим
  // под тэг конкретного итератора. Это всё происходит при компиляции: для конкретного
  // типа итератора T компилятор генерирует свою копию my_binary_search, которая создаёт
  // тэг определённого типа, после чего выбирается определённая перегрузка my_binary_search.
  return my_binary_search(begin, end, value, std::iterator_traits<T>::iterator_category());
}

// Старый код.

int main() {
  std::vector<int> v;
  fill(v);
  check(v);

  std::list<int> l;
  fill(l);
  check(l);
  return 0;
}
