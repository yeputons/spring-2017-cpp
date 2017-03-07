#include <cstdio>
#include <cstring>
#include <memory>

class Object {
public:
  Object() : x(123) {
    printf("Object()\n");
    name = new char[3];
    strcpy(name, "me");
  }
  // TODO: implement copy constructor
  // TODO: implement assignment operator
  ~Object() {
    printf("~Object() name=%p\n", name);
    delete[] name;
    name = NULL;
  }

  int x;
  char *name;
};

char buf[1024 * 1024];

int main() {
/*  Object *o = (Object*)(buf + 230);

  new (o) Object;  // placement new

  printf("%d\n", o->x);

  o->~Object(); // explicit destructor call
  for (int i = 0; i < 16; i++)
    printf("%02x\n", buf[230 + i]);
//  o->~Object(); // explicit destructor call
*/
  Object *o = (Object*)new char[sizeof(Object)];
  printf("memory allocated\n");

  new (o) Object;
  printf("ctor finished\n");

  o->~Object();
  printf("dtor finished\n");
 
  //delete o; // o is 'Object*'
  //delete o;
  delete[] (char*)o;
  printf("memory deallocated\n");
}
