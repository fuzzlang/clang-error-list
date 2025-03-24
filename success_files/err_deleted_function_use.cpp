
namespace A {
  enum E {};
  template<typename R, typename A>
  void foo(E, R (*)(A)); // #cwg352-foo
}

template<typename T>
void arg(T);
template<typename T>
int arg(T) = delete; // #cwg352-deleted

void f(A::E e) {
  using A::foo;
  foo<int, int>(e, &arg);
  // expected-error@-1 {{attempt to use a deleted function}}
  // expected-note@#cwg352-deleted {{'arg<int>' has been explicitly marked deleted here}}
}

int main() {
  A::E e;
  f(e);
}
