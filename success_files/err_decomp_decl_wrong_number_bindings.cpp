
namespace cwg2363 {
struct MyEnum {
  enum class Color { Red, Green, Blue };
  // expected-error@-2 {{elaborated enum specifier cannot be declared as a friend}}
  // expected-note@-3 {{remove 'enum class' to befriend an enum}}
  friend void useColor(Color);
};
} // namespace cwg2363

namespace cwg2370 {
namespace N {
typedef int type;
void g(type);
void h(type);
} // namespace N

class C {
  typedef N::type N_type;
  // friend void N::g(type);  // Uncommenting this will not raise an error
  friend void N::h(N_type);
};
} // namespace cwg2370

#if __cplusplus >= 201702L
namespace cwg2386 {
struct Bad1 { int a, b; };
struct Bad2 { int a, b; };
} // namespace cwg2386

namespace std {
template <typename T> struct tuple_size;
template <> struct tuple_size<cwg2386::Bad1> {};
template <> struct tuple_size<cwg2386::Bad2> {
  static const int value = 42;
};
} // namespace std

namespace cwg2386 {
void no_value() { auto [x, y] = Bad1(); }
void wrong_value() { auto [x, y] = Bad2(); } // expected-error {{expression is not assignable}}
}
#endif
