
struct Data { };

struct T {
  Data *begin();
  Data *end();
};

void f() {
  T *pt;
  for (auto i : pt) { } // expected-error{{invalid range expression of type 'T *'; did you mean to dereference it with '*'?}}
}
