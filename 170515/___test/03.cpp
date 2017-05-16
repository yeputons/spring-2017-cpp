#include <list>
#include <string>
#include <memory>
#include "person.h"

int main() {
  std::list<std::unique_ptr<Person>> list;
  std::unique_ptr<Person> ptr(new Person("vasya", 17));
  list.push_back(std::move(ptr));
  return 0;
}
