#ifndef PERSON_H_
#define PERSON_H_

#include <string>

struct Person {
  Person(std::string init_name, int init_age) : name(init_name), age(init_age) {}

  std::string name;
  int age;
};

#endif  // PERSON_H_