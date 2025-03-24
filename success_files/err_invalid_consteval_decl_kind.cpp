
namespace invalid_function {

struct A {
  consteval void *operator new(size_t count); // expected-error@-1 {{take address}}
};

}
