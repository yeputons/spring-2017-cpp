#include <time.h>
#include <vector>
#include <iostream>
#include "person.h"

std::vector<Person> persons;

void calc() {
  int with_passport_num = 0;
  for (auto &p : persons) {
  	if (p.age > 14) with_passport_num++;
  }
}

int main() {
  for (int i = 0; i < 10000; i++) {
    std::string name(1000, '?');
    persons.push_back(Person(name, i));
  }

  std::cout << "Running...\n";
  clock_t start = clock();
  for (int i = 0; i < 1000; i++) {
    calc();
  }
  std::cout << (clock() - start) * 1.0 / CLOCKS_PER_SEC << " sec\n";
  return 0;
}
