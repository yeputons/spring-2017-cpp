struct Person {
  std::tring name;
  int age;
};

void permutation(vector<Person>& v)   {
  vector<int> indices(v.size());
  int count = 0;
  generate(indices.begin(), indices.end(), [&count](){ return ++count; });
/*
  struct age_comparator {
      const vector<Person>& vec;
      age_comparator(const vector<Person>& v) : vec(v) { }
      bool operator()(int i1, int i2) const { return vec[i1].age < vec[i2].age; }
  };
  sort(indices.begin(), indices.end(), age_comparator(v));  
*/
  sort(indices.begin(), indices.end(), [&v](int i1, int i2) {
    return v[i1].age < v[i2].age;
  });

}

int main() {
  return 0;
}
