
#if __cplusplus >= 201103L
namespace cwg1601 { // cwg1601: 10
enum E : char { e };
// expected-error@-1 {{enumeration types with a fixed underlying type are a C++11 extension}}
void f(char);
void f(int);
void g() {
  f(e);
}
} // namespace cwg1601

namespace cwg1638 { // cwg1638: 3.1
  template<typename T> struct A {
    enum class E; // #cwg1638-E
    enum class F : T; // #cwg1638-F
  };

  template<> enum class A<int>::E;
  // expected-error@-1 {{enumeration redeclared with different underlying type 'int' (was 'short')}}
  template<> enum class A<short>::F;
  template<> enum class A<char>::E : char;
  // expected-error@-1 {{enumeration redeclared with different underlying type 'char' (was 'int')}}
  template<> enum class A<unsigned>::E;
  // expected-error@-1 {{template specialization requires 'template<>'}}
  template enum class A<unsigned>::E;
  // expected-error@-1 {{enumerations cannot be explicitly instantiated}}
  enum class A<unsigned>::E *e;
}
#endif
