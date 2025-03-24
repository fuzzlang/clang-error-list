
template<typename T>
struct S {
  T f; // expected-error{{data member instantiated with function type 'float (int)'}}
};

float g(int);

int main() {
  S<decltype(g)> s;
  return 0;
}
