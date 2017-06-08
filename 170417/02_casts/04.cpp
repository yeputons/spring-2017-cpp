A
| \
B  C
|
D


A* foo;
B* foo_b = dynamic_cast<B*>(foo);


A &foo;
B &foo_b = dynamic_cast<B&>(foo);


dynamic_cast<int*>(char*);


struct Foo {
  int a;
};
struct Bar : Foo {
  int b;
};
struct Baz : Foo {
  int b;
};


vector<A*> objs;
vector<B*> obj_b;
vector<С*> obj_с;
for (A* a : objs) {
  B* b = dynamic_cast<B*>(a);
  С* с = dynamic_cast<С*>(a);
  if (b) {
    obj_b.push_back(b);
  } else {
    obj_c.push_back(c);
  }
}

vector<A*> objs;
for (A* a : objs) {
  B* b = dynamic_cast<B*>(a);
  С* с = dynamic_cast<С*>(a);
  if (b) {
    cout << b.field1;
  } else {
    cout << c.field2;
  }
}


Parent p = child;
